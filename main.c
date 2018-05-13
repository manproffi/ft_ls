/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:06:35 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 14:06:38 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	pr_list(t_list * lst)
{
	while(lst)
	{
		printf("%-s\t", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

int 	main(int argc, char *argv[])
{
	t_info		info;
	int			count_arg;
	// t_list		*list = NULL;

	info.flags = 0;
	read_window_parameters(&info);

	count_arg = parsing_command(argc, argv, &info);
	work_with_parameters(count_arg, argc, argv, &info);

	// del_list_list(&list);
	return 0;
}
