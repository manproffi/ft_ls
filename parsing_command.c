/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:38:21 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 14:38:23 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	list_flag(t_info * info, int i, int j, char * argv[])
{
	int		flag_correct;

	flag_correct = info->flags;
	info->flags = (argv[i][j] == 'l') ? (info->flags | 1) : (info->flags);
	info->flags = (argv[i][j] == 'R') ? (info->flags | 2) : (info->flags);
	info->flags = (argv[i][j] == 'a') ? (info->flags | 4) : (info->flags);
	info->flags = (argv[i][j] == 't') ? (info->flags | 8) : (info->flags);
	info->flags = (argv[i][j] == '1') ? (info->flags | 16) : (info->flags);
	info->flags = (argv[i][j] == 'g') ? (info->flags | 32) : (info->flags);
	info->flags = (argv[i][j] == 'i') ? (info->flags | 64) : (info->flags);
	info->flags = (argv[i][j] == 'r') ? (info->flags | 128) : (info->flags);
	if (flag_correct == info->flags)
	{
		printf("ERROR: Unknown flag\n");
		exit(1);
	}
}

int		parsing_command(int argc, char * argv[], t_info * info)
{
	int			i;
	int			j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (++j < ft_strlen(argv[i]))
				list_flag(info, i , j, argv);
		}
		else
			break ;
	}
	return (i);
}
