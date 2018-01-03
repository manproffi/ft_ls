/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:16:30 by sprotsen          #+#    #+#             */
/*   Updated: 2017/12/22 18:16:32 by sprotsen         ###   ########.fr       */
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
}

void	read_width(t_info * info)
{
	struct winsize ws;
	
	if ((ioctl(0, TIOCGWINSZ, &ws)) != -1)
	{
		info->w = ws.ws_col;
		info->h = ws.ws_row;
	}
	else
	{
		perror("ERROR");
		exit(1);
	}
}

int		main(int argc, char const *argv[])
{
	t_info 		info;

	info.flag = 0;
	read_width(&info);
	// printf("w: %d h: %d\n\n", info.w, info.h);

	if (argc == 1)
	{
		// printf("чистый вызов ls без флагов и аргументов\n");
		// pure_command(&info);
	}
	else
	{
		parsing_command(argc, argv, &info);
	}
	// free(info.mass);
	// if (argc == 1)
	// 	pure_command();


	// printf("========\n");

	// ft_printf("%-*s\n", 10, "qwerty");

	// sleep(42);

	return (0);
}