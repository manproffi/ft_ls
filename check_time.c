/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:02:44 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/20 16:02:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

char	*check_time(struct stat *p_stat)
{
	char	*res;
	char	*year;
	time_t	ct;

	ct = time(NULL);
	if (ct - p_stat->st_mtimespec.tv_sec <= HALF_YEAR)
		res = ft_strsub(ctime(&p_stat->st_mtimespec.tv_sec), 4, 12);
	else
	{
		res = ft_strsub(ctime(&p_stat->st_mtimespec.tv_sec), 4, 12);
		year = ft_strsub(ctime(&p_stat->st_mtimespec.tv_sec), 20, 4);
		res[7] = ' ';
		res[8] = year[0];
		res[9] = year[1];
		res[10] = year[2];
		res[11] = year[3];
		ft_strdel(&year);
	}
	return (res);
}
