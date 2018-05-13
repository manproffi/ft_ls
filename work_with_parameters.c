/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:25:28 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 17:25:34 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	next_stage(t_list *list, t_info * info)
{
	t_list ** tmp;

	tmp = sort(list, info);
	if ((info->flags & 2) == 1)
	{
		//TODO recursion
		;
	}
	else
		print_column(info, tmp, ft_lstsize(list));
	del_list_list(&list);
	//TODO delete mass tmp
}

void		work_with_parameters(int c_arg, int ac, char **av, t_info *info)
{
	t_list	*list;

	if (ac == c_arg)
	{
		list = reading(info, ".");
		
		next_stage(list, info);
	}
	while (--ac >= c_arg)
	{
		list = reading(info, av[ac]);
		next_stage(list, info);
	}
}