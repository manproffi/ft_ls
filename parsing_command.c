/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:35:13 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/19 21:35:16 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

int		check_flag(char c)
{
	static char row[] = "altrR1gi";
	int			i;

	i = -1;
	while (++i < 8)
		if (c == row[i])
			return (1);
	return (0);
}

void	list_flag(t_info *info, int i, int j, char *argv[])
{
	int		flag_correct;

	flag_correct = info->flags;
	info->flags = (argv[i][j] == 'l') ? (info->flags | 1) : (info->flags);
	info->flags = (argv[i][j] == 'R') ? (info->flags | 2) : (info->flags);
	info->flags = (argv[i][j] == 'a') ? (info->flags | 4) : (info->flags);
	info->flags = (argv[i][j] == 't') ? (info->flags | 8) : (info->flags);
	if (argv[i][j] == '1')
	{
		info->flags = (info->flags | 16);
		info->flags &= ~(1UL << 0);
	}
	info->flags = (argv[i][j] == 'g') ? (info->flags | 32) : (info->flags);
	info->flags = (argv[i][j] == 'i') ? (info->flags | 64) : (info->flags);
	info->flags = (argv[i][j] == 'r') ? (info->flags | 128) : (info->flags);
	if (flag_correct == info->flags)
	{
		if (check_flag(argv[i][j]))
			return ;
		ft_printf("ft_ls: illegal option -- %c\n", argv[i][j]);
		ft_printf("usage: ./ft_ls [-altrR1gi]\n");
		exit(1);
	}
}

int		parsing_command(int argc, char *argv[], t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (++j < (int)ft_strlen(argv[i]))
				list_flag(info, i, j, argv);
		}
		else
			break ;
	}
	return (i);
}
