/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 21:10:05 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/15 21:10:07 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

int		len_number(long long a)
{
	int		res;

	res = 0;
	while (1)
	{
		if (a / 10 == 0)
			return (res + 1);
		else
		{
			a = a / 10;
			res++;
		}
	}
	return (0);
}

void	flag_i(t_list **mass, int size, char *name)
{
	struct stat			p_stat;
	char				*str_name;
	int					i;
	unsigned long long	index[size];
	int					max;

	i = -1;
	max = 0;
	while (++i < size)
	{
		str_name = ft_strjoin(name, mass[i]->content);
		if (lstat(str_name, &p_stat) == 0)
		{
			index[i] = p_stat.st_ino;
			if (max < len_number(index[i]))
				max = len_number(index[i]);
		}
		ft_strdel(&str_name);
	}
	i = -1;
	while (++i < size)
		ft_printf("%*d %s\n", max, index[i], mass[i]->content);
}
