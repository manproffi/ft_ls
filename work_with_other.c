/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:49:54 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/28 17:49:55 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	work_with_other(t_list **mass, int size, t_info *info)
{
	int		i;
	t_list	*list;
	int		flag_file;

	i = -1;
	flag_file = 0;
	info->fl_print_total = 1;
	while (++i < size)
	{
		list = reading(info, mass[i]->content, &flag_file);
		ft_printf("%s:\n", mass[i]->content);
		next_stage(list, info, mass[i]->content, &flag_file);
		i == size - 1 ? 0 : ft_printf("\n");
	}
}
