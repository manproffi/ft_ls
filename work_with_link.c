/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:11:34 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/28 16:11:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	work_with_link(t_list **mass, int size, t_info *info)
{
	t_list	*list;
	int		flag_file;
	int		i;

	flag_file = 0;
	list = NULL;
	i = -1;
	if ((info->flags & 1) == 1)
	{
		while (++i < size)
		{
			check_is_link(mass[i]->content, info, &flag_file);
		}
	}
	else
	{
		while (++i < size)
		{
			list = reading(info, mass[i]->content, &flag_file);
			next_stage(list, info, mass[i]->content, &flag_file);
		}
	}
}
