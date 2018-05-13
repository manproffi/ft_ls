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

int 	main(int argc, char const *argv[])
{
	t_info		info;

	info.flags = 0;
	read_window_parameters(&info);

	printf("%d\n", info.h_window);
	printf("%d\n", info.w_window);

	if (argc == 1)
	{
		printf("%s\n", "invoke ft_ls without parameters");
	}
	else
	{

	}
	return 0;
}
