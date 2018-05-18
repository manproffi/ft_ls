/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:33:39 by sprotsen          #+#    #+#             */
/*   Updated: 2018/01/08 15:33:40 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	get_strmode(mode_t mode, char * buf, char *name)
{
	const char chars[] = "rwxrwxrwx";
	// size_t			buffler;

	for (size_t i = 0; i < 9; i++) {
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
	}
	if (mode & S_ISUID)
		buf[2] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		buf[5] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		buf[8] = (mode & S_IXOTH) ? 't' : 'T';
	// 	printf("asdfasdf\n");
	// else
	// 	printf("NNNNNNN\n");
	/*
	** http://man7.org/linux/man-pages/man2/listxattr.2.html
	*/
	buf[9] = get_extended_atribute(name);
	//printf("%zu\n", listxattr(name, NULL, 0, XATTR_NOFOLLOW));
	// if (listxattr(name, NULL, 0, XATTR_NOFOLLOW) > 0)
	// 	buf[9] = '@';

	
	buf[10] = '\0';

}



int		for_readlink(t_list **mass, int i, char * add_name, int len_name)
{
	// char buffer[256];
	char * qwe;
	char * tmp;
	// int	j;

	// j = -1;
	// while (++j < 256)
	// 	buffer[j] = '\0';
	// printf("+++++++%s %d\n", add_name, len_name);
	
	add_name[len_name] = '\0';

	qwe = ft_strjoin(" -> ", add_name);
	// printf("!!!!!!: %s %s\n", qwe, add_name);
	tmp = mass[i]->content;
	mass[i]->content = ft_strjoin(tmp, qwe);
	ft_strdel(&qwe);
	ft_strdel(&tmp);
	return 0;
}



void	block_reading(int size, t_print *pr, int i, t_list **mass)
{
	int				len_symlink_name;
	struct stat  	p_stat;

	len_symlink_name = 0;
	lstat(pr[i].new_name, &p_stat);
	pr[i].c = get_filetype(p_stat.st_mode);
	get_strmode(p_stat.st_mode, pr[i].buf, pr[i].new_name);
	pr[i].h_link = p_stat.st_nlink;
	// perror("HERE");
	pr[i].pw = getpwuid(p_stat.st_uid);
	// perror("******");
	pr[i].gr = getgrgid(p_stat.st_gid);

	// printf("%s\n", pr[i].pw->pw_name);
	// printf("%s\n", pr[i].gr->gr_name);
	//printf("%s\t", pr[i].new_name);
	// perror("++++++");
	pr[i].file_size = p_stat.st_size;
	// pr[i].str_time = ft_strsub(ctime(&(p_stat.st_mtimespec.tv_sec)), 4, 12);
	pr[i].str_time = NULL;

	if ((len_symlink_name = readlink(pr[i].new_name, pr[i].buffer, 256)) > 0)
		for_readlink(mass, i, pr[i].buffer, len_symlink_name);
	pr[i].file_name = ft_strdup(mass[i]->content);
	pr[i].total = p_stat.st_blocks;
}

void	final_print(int size, t_print *pr)
{
	int			i;
	blkcnt_t 	total;
	int			first_len;
	int			second_len;

	i = -1;
	first_len = 0;
	second_len = 0;
	total = 0;
	while (++i < size)
	{
		total += pr[i].total;
		first_len = first_len < pr[i].h_link ? pr[i].h_link : first_len;
		second_len = second_len < pr[i].file_size ? pr[i].file_size : second_len;
	}
	i = -1;	
	if (size)
		printf("total %lld\n", total);
	while (++i < size)
	{

// pr[i].c



// pr[i].buf
// len_number(first_len)
// pr[i].h_link

// pr[i].pw->pw_name
// pr[i].gr->gr_name

		// printf(RED"%p  %p %p %p %p \n"RESET, pr[i].c, pr[i].buf, pr[i].h_link, pr[i].pw->pw_name, pr[i].gr->gr_name);//, len_number(second_len), pr[i].file_size);//, pr[i].str_time, pr[i].file_name);



		printf(RED"%p %10s %hhd  %hhd %s  %lld %s %s\n"RESET, pr[i].c, pr[i].buf, pr[i].h_link, pr[i].pw->pw_name, pr[i].gr->gr_name, pr[i].file_size, pr[i].str_time, pr[i].file_name);





		// printf(RED"%c%s %*d  %s %s  %*lld %s %s\n"RESET, pr[i].c, pr[i].buf, len_number(first_len), pr[i].h_link, pr[i].pw->pw_name, pr[i].gr->gr_name,
		// 	len_number(second_len), pr[i].file_size, pr[i].str_time, pr[i].file_name);
		ft_strdel(&pr[i].new_name);
		ft_strdel(&pr[i].str_time);
		ft_strdel(&pr[i].file_name);
	}
}


void	flag_l(int size, t_list **mass, char const * name)
{
	t_print		*pr;
	int 		i;

	pr = (t_print*)malloc(sizeof(t_print) * size);
	if (!pr)
		perror("ERROR maloc");
	i = -1;
	while (++i < size)
	{
		pr[i].new_name = ft_strjoin(name, mass[i]->content);
		block_reading(size, pr, i, mass);
	}

	
	final_print(size, pr);
	if (pr)
		free(pr);
}
