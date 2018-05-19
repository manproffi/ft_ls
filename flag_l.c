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
	const char chars[] = "rwxrwxrwx ";
	for (size_t i = 0; i < 9; i++) {
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
	}
	if (mode & S_ISUID)
		buf[2] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		buf[5] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		buf[8] = (mode & S_IXOTH) ? 't' : 'T';
	buf[9] = get_extended_atribute(name);
	buf[10] = '\0';

}



int		for_readlink(t_list **mass, int i, char *name)
{
	// char buffer[256];
	char * qwe;
	char * tmp;
	int	len_symlink_name;
	char			buffer[256];
	// int	j;

	// j = -1;
	// while (++j < 256)
	// 	buffer[j] = '\0';
	// printf("+++++++%s %d\n", add_name, len_name);
	len_symlink_name = readlink(name, buffer, 256);
	
	buffer[len_symlink_name] = '\0';

	qwe = ft_strjoin(" -> ", buffer);
	// printf("!!!!!!: %s %s\n", qwe, add_name);
	tmp = mass[i]->content;
	mass[i]->content = ft_strjoin(tmp, qwe);
	ft_strdel(&qwe);
	ft_strdel(&tmp);
	return 0;
}



void	block_reading(int size, t_print *pr, int i, t_list **mass)
{
	struct stat  	p_stat;
	struct passwd 	*pw;
	struct group  	*gr;

	// printf("%s\n", pr[i].new_name);
	// /pr[i].new_name = ft_strdup("/tmp/com.apple.launchd.6zYDHnKk5G/");
	
	lstat(pr[i].new_name, &p_stat);
	// perror(pr[i].new_name);

	pr[i].c = get_filetype(p_stat.st_mode);
	get_strmode(p_stat.st_mode, pr[i].buf, pr[i].new_name);
	pr[i].h_link = p_stat.st_nlink;
	// pr[i].pw = NULL;
	
	if ((pw = getpwuid(p_stat.st_uid)) != NULL)
		pr[i].pw_name = ft_strdup(pw->pw_name);
	// pr[i].gr = getgrgid(p_stat.st_gid);
	if ((gr = getgrgid(p_stat.st_gid)) != NULL)
		pr[i].gr_name = ft_strdup(gr->gr_name);

	// printf("%s\n", pr[i].gr->gr_name);
	
	pr[i].file_size = p_stat.st_size;
	pr[i].str_time = ft_strsub(ctime(&(p_stat.st_mtimespec.tv_sec)), 4, 12);


	if (S_ISLNK(p_stat.st_mode))
		for_readlink(mass, i, pr[i].new_name);



	pr[i].file_name = ft_strdup(mass[i]->content);
	pr[i].total = p_stat.st_blocks;
}

void	final_print(int size, t_print *pr, t_info *info)
{
	int			i;
	blkcnt_t 	total;
	int			len[4];

	i = -1;

	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;

	total = 0;
	while (++i < size)
	{
		total += pr[i].total;
		len[0] = len[0] < len_number(pr[i].h_link) ? len_number(pr[i].h_link) : len[0];
		len[1] = len[1] < ft_strlen(pr[i].pw_name) ? ft_strlen(pr[i].pw_name): len[1];
		len[2] = len[2] < ft_strlen(pr[i].gr_name) ? ft_strlen(pr[i].gr_name) : len[2];
		len[3] = len[3] < len_number(pr[i].file_size) ? len_number(pr[i].file_size) : len[3];


	}

	i = -1;	
	if (size)
		printf("total %lld\n", total);


	if (((info->flags & 32) == 32))
	{
				while (++i < size)
		{
			printf(RED"%c%s %*hu  %-*s  %*lld %s %s\n"RESET, pr[i].c, pr[i].buf, len[0], pr[i].h_link, len[2], pr[i].gr_name,
				len[3], pr[i].file_size, pr[i].str_time, pr[i].file_name);
			ft_strdel(&pr[i].gr_name);
			ft_strdel(&pr[i].pw_name);
			ft_strdel(&pr[i].new_name);
			ft_strdel(&pr[i].str_time);
			ft_strdel(&pr[i].file_name);
		}
	}
	else 
	{
		while (++i < size)
		{
			printf(RED"%c%s %*hu %-*s  %-*s  %*lld %s %s\n"RESET, pr[i].c, pr[i].buf, len[0], pr[i].h_link, len[1], pr[i].pw_name, len[2], pr[i].gr_name,
				len[3], pr[i].file_size, pr[i].str_time, pr[i].file_name);
			ft_strdel(&pr[i].gr_name);
			ft_strdel(&pr[i].pw_name);
			ft_strdel(&pr[i].new_name);
			ft_strdel(&pr[i].str_time);
			ft_strdel(&pr[i].file_name);
		}
	}


}


void	flag_l(int size, t_list **mass, char const * name, t_info *info)
{
	t_print		*pr;
	int			i;

	pr = (t_print*)malloc(sizeof(t_print) * size);
	if (!pr)
		perror("ERROR maloc");
	i = -1;
	while (++i < size)
	{
		pr[i].new_name = ft_strjoin(name, mass[i]->content);
		block_reading(size, pr, i, mass);
	}

	final_print(size, pr, info);
	if (pr)
		free(pr);
}
