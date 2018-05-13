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
	int 	marker_for_address;
	int		flag_file;

	flag_file = 0;
	if (ac == c_arg)
	{
		list = reading(info, ".", &flag_file);
		next_stage(list, info);
	}
	marker_for_address = ac - c_arg;
	while (--ac >= c_arg)
	{
		//printf("%d\n", marker_for_address);
		list = reading(info, av[ac], &flag_file);
		if (marker_for_address > 1 && !flag_file)
			printf("%s:\n", av[ac]);
		else
			flag_file = 0;
		next_stage(list, info);
		ac != c_arg ? printf("\n"): 0 ;
	}
}