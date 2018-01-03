/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:20:42 by sprotsen          #+#    #+#             */
/*   Updated: 2017/12/23 13:20:44 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"


void	list_flag(t_info * info, int i, int j, char const *argv[])
{
	int		flag_correct;

	flag_correct = info->flag;
	info->flag = (argv[i][j] == 'l') ? (info->flag | 1) : (info->flag);
	info->flag = (argv[i][j] == 'R') ? (info->flag | 2) : (info->flag);
	info->flag = (argv[i][j] == 'a') ? (info->flag | 4) : (info->flag);
	info->flag = (argv[i][j] == 't') ? (info->flag | 8) : (info->flag);
	if (flag_correct == info->flag)
	{
		printf("ERROR: Unknown flag\n");
		exit(1);
	}
}


void	parsing_command(int argc, char const *argv[], t_info * info)
{
	int			i;
	int			j;
	int			len;
	int			flag_correct;
	t_list		*list;

	i = 0;
	while(++i < argc)
	{
		if (argv[i][0] == '-')
		{
			len = ft_strlen(argv[i]);
			j = 0;
			while(++j < len)
				list_flag(info, i , j, argv);
		}
		else if (info->flag == 0)
		{
			// printf("нет флагов и есть аргументы для ls\n");
			list = reading(info, argv[i]);
			pr_list(list);
			printf("+++++++++++++++\n");
			// working_with_arguments(list, )
			
		}
		else
		{
			// printf("применить флаги ls и \n");
			// printf("реагировать на все далее как на папки и файлы\n");
			// printf("==============\n");
			work_with_flags(argc, i, info, argv);




			break;
		}
		// printf("rezult: %d\n", info->flag);
	}
	// while(i < argc)
	// {
	// 	list = reading(info, argv[i]);
	// 	// pr_list(list);
	// 	del_list_list(&list);
	// 	i++;
	// }
}
