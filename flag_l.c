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

void	get_strmode(mode_t mode, char *buf, char *name)
{
	const char	chars[] = "rwxrwxrwx";
	int			i;

	i = -1;
	while (++i < 9)
		buf[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
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
	char	*qwe;
	char	*tmp;
	int		len_symlink_name;
	char	buffer[256];

	len_symlink_name = readlink(name, buffer, 256);
	buffer[len_symlink_name] = '\0';
	qwe = ft_strjoin(" -> ", buffer);
	tmp = mass[i]->content;
	mass[i]->content = ft_strjoin(tmp, qwe);
	ft_strdel(&qwe);
	ft_strdel(&tmp);
	return (0);
}

void	block_reading(t_print *pr, int i, t_list **mass)
{
	struct stat		p_stat;
	struct passwd	*pw;
	struct group	*gr;

	pr[i].maj = 0;
	pr[i].min = 0;
	lstat(pr[i].new_name, &p_stat);
	pr[i].c = get_filetype(p_stat.st_mode);
	get_strmode(p_stat.st_mode, pr[i].buf, pr[i].new_name);
	pr[i].h_link = p_stat.st_nlink;
	if ((pw = getpwuid(p_stat.st_uid)) != NULL)
		pr[i].pw_name = ft_strdup(pw->pw_name);
	if ((gr = getgrgid(p_stat.st_gid)) != NULL)
		pr[i].gr_name = ft_strdup(gr->gr_name);
	pr[i].file_size = p_stat.st_size;
	pr[i].str_time = check_time(&p_stat);
	if (S_ISLNK(p_stat.st_mode))
		for_readlink(mass, i, pr[i].new_name);
	pr[i].file_name = ft_strdup(mass[i]->content);
	pr[i].total = p_stat.st_blocks;
	if (S_ISCHR(p_stat.st_mode) || S_ISBLK(p_stat.st_mode))
	{
		pr[i].maj = major(p_stat.st_rdev);
		pr[i].min = minor(p_stat.st_rdev);
	}
}

void	final_print(int size, t_print *pr, t_info *info, int flag_file)
{
	int			i;
	blkcnt_t	total;
	int			len[6];

	i = -1;
	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
	len[4] = size;
	total = 0;
	len[5] = flag_file;
	while (++i < size)
	{
		total += pr[i].total;
		len[0] = len[0] < len_number(pr[i].h_link) ?
			len_number(pr[i].h_link) : len[0];
		len[1] = (size_t)len[1] < ft_strlen(pr[i].pw_name) ?
			ft_strlen(pr[i].pw_name) : len[1];
		len[2] = (size_t)len[2] < ft_strlen(pr[i].gr_name) ?
			ft_strlen(pr[i].gr_name) : len[2];
		len[3] = len[3] < len_number(pr[i].file_size) ?
			len_number(pr[i].file_size) : len[3];
	}
	printing_part1(len, total, info, pr);
}

void	flag_l(int size, t_list **mass, char const *name, t_info *info)
{
	t_print		*pr;
	int			i;
	int			flag_file;

	flag_file = 0;
	pr = (t_print*)malloc(sizeof(t_print) * size);
	if (!pr)
		perror("ERROR maloc");
	i = -1;
	while (++i < size)
	{
		if (name[ft_strlen(name) - 1] == '/')
			pr[i].new_name = ft_strjoin(name, mass[i]->content);
		else
		{
			flag_file = -1;
			pr[i].new_name = ft_strdup(name);
		}
		block_reading(pr, i, mass);
	}
	final_print(size, pr, info, flag_file);
	if (pr)
		free(pr);
}
