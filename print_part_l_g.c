/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_part_l_g.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:16:31 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/19 21:22:48 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"
#define FT_P	ft_printf

void	pr_flag_g(int size, t_print *pr, int len[5], int l[2])
{
	int		i;

	i = -1;
	len[3] += (l[1] + l[0] - 1);
	while (++i < size)
	{
		if (pr[i].c == 'c' || pr[i].c == 'b')
		{
			FT_P("%c%s %*d %-*s  %-*s   %*d,%*d %s %s\n", pr[i].c, pr[i].buf,
			len[0], pr[i].h_link, len[1], pr[i].pw_name, len[2], pr[i].gr_name,
			l[0], pr[i].maj, l[1], pr[i].min, pr[i].str_time, pr[i].file_name);
		}
		else
		{
			FT_P("%c%s %*d %-*s %*d %s %s\n", pr[i].c, pr[i].buf,
				len[0], pr[i].h_link, len[2], pr[i].gr_name,
				len[3], pr[i].file_size, pr[i].str_time, pr[i].file_name);
		}
		ft_strdel(&pr[i].gr_name);
		ft_strdel(&pr[i].pw_name);
		ft_strdel(&pr[i].new_name);
		ft_strdel(&pr[i].str_time);
		ft_strdel(&pr[i].file_name);
	}
}

void	pr_flag_l(int size, t_print *pr, int len[5], int l[2])
{
	int		i;

	i = -1;
	len[3] += l[1];
	l[1] -= 1;
	while (++i < size)
	{
		if (pr[i].c == 'c' || pr[i].c == 'b')
		{
			FT_P("%c%s %*d %-*s  %-*s   %*d,%*d %s %s\n", pr[i].c, pr[i].buf,
			len[0], pr[i].h_link, len[1], pr[i].pw_name, len[2], pr[i].gr_name,
			l[0], pr[i].maj, l[1], pr[i].min, pr[i].str_time, pr[i].file_name);
		}
		else
		{
			FT_P("%c%s %*d %-*s  %-*s %*d %s %s\n", pr[i].c, pr[i].buf,
			len[0], pr[i].h_link, len[1], pr[i].pw_name, len[2], pr[i].gr_name,
			len[3], pr[i].file_size, pr[i].str_time, pr[i].file_name);
		}
		ft_strdel(&pr[i].gr_name);
		ft_strdel(&pr[i].pw_name);
		ft_strdel(&pr[i].new_name);
		ft_strdel(&pr[i].str_time);
		ft_strdel(&pr[i].file_name);
	}
}

void	printing_part1(int len[5], blkcnt_t total, t_info *info, t_print *pr)
{
	int		i;
	int		len_minor_major[2];
	int		size;

	i = -1;
	size = len[4];
	len_minor_major[0] = 0;
	len_minor_major[1] = 0;
	while (++i < size)
	{
		len_minor_major[0] = len_minor_major[0] < len_number(pr[i].maj) ?
			len_number(pr[i].maj) : len_minor_major[0];
		len_minor_major[1] = len_minor_major[1] < len_number(pr[i].min) ?
			len_number(pr[i].min) : len_minor_major[1];
	}
	if (size && len[5] != -1 && info->fl_print_total != -1)
		FT_P("total %d\n", total);
	if (((info->flags & 32) == 32))
	{
		pr_flag_g(size, pr, len, len_minor_major);
	}
	else
	{
		pr_flag_l(size, pr, len, len_minor_major);
	}
}
