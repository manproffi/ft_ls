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

void	next_stage(t_list *list, t_info * info, char * name)
{
	t_list ** tmp;
	char 	*str_name;

	 // printf("%s\n", name);
	
	if (name[ft_strlen(name) - 1] == '/')
		str_name = ft_strdup(name);
	else
		str_name = ft_strjoin(name, "/");
	

	tmp = sort(list, info, name);


	choise_print_fun(info, tmp, ft_lstsize(list), str_name);
	if ((info->flags & 2) == 2)
		resursion(info, tmp, ft_lstsize(list), ft_strjoin(name, "/"));
	del_list_list(&list);
	if (tmp)
		free(tmp);
}

void		work_with_parameters(int c_arg, int ac, char **av, t_info *info)
{
	t_list	*list;
	int 	marker_for_address;
	int		flag_file;

	flag_file = 0;
	if (ac == c_arg) //&& info->flags == 0)
	{
		list = reading(info, ".", &flag_file);
		next_stage(list, info, ".");
	}
	// printf("sadfasdf\n");
	marker_for_address = ac - c_arg;
	while (--ac >= c_arg)
	{
		//printf("%d\n", marker_for_address);
		list = reading(info, av[ac], &flag_file);
		if (marker_for_address > 1 && !flag_file)
			printf("%s:\n", av[ac]);
		else
			flag_file = 0;
		next_stage(list, info, av[ac]);
		ac != c_arg ? printf("\n"): 0 ;
	}
}
