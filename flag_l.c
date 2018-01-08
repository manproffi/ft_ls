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

void	get_strmode(mode_t mode, char * buf)
{
	const char chars[] = "rwxrwxrwx";
	for (size_t i = 0; i < 9; i++) {
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
	}
	buf[9] = '\0';
}


void	flag_l(int size, t_list **mass, char const * name)
{
	// printf("%s\n", name);

	struct stat  p_stat;
	
	char buf[10];

	stat(name, &p_stat);

	blkcnt_t a;
	a = 0;
	// printf(RED"total: %s %lld\n"RESET, name, p_stat.st_blocks );
	// printf("%s\n", name);

	// get_strmode(p_stat.st_mode, buf);
	// // get_filetype(p_stat.st_mode)
	// printf(RED"%c%s\n"RESET, get_filetype(p_stat.st_mode), buf);

	int i = -1;
	while (++i < size)
	{
		// printf("%s\t%s\n", name, mass[i]->content);
		char * str_name = ft_strjoin(name, mass[i]->content);
		stat(str_name, &p_stat);
		// ft_printf(GREEN"blocks: %lld\n"RESET, p_stat.st_blocks);
		get_strmode(p_stat.st_mode, buf);
		/**** owner and group ****/
		struct passwd *pw = getpwuid(p_stat.st_uid);
		struct group  *gr = getgrgid(p_stat.st_gid);

		/**** time ****/
		char * str_time = ft_strsub(ctime(&(p_stat.st_mtimespec.tv_sec)), 4, 12);
	
		a += p_stat.st_blocks;
		// printf(RED"total: %s %d\n"RESET, name, p_stat.st_blocks );
		


		char buffer[256];
		for (int j = 0; j < 256; ++j)
			buffer[i] = '\0';
		// printf("%zd\n", readlink(str_name, buffer, 256));
		if (readlink(str_name, buffer, 256) > 0)
		{
			// printf("%s\n", buffer);
			char * qwe = ft_strjoin(" -> ", buffer);
			char * tmp = mass[i]->content;
			mass[i]->content = ft_strjoin(tmp, qwe);
			ft_strdel(&qwe);
			ft_strdel(&tmp);

		}
		// printf("%zd\n", readlink(name, str_name, 100));

		printf(RED"%c%s  %d %s  %s  %5lld %s %s\n"RESET, get_filetype(p_stat.st_mode), buf, p_stat.st_nlink, 
			pw->pw_name, gr->gr_name, p_stat.st_size, str_time, mass[i]->content);
		ft_strdel(&str_name);
		ft_strdel(&str_time);

		


	}
	printf("%d\n", a);
}
