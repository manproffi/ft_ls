/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 20:06:55 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/14 20:06:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

int		check_if_dir(char * name)
{
	 struct stat  p_stat;

	if (lstat(name, &p_stat) == 0 && S_ISDIR(p_stat.st_mode))
		return 1;
	return 0;
}


void	resursion(t_info *info, t_list **mass, int size, char *name)
{
	int		i;
	int		flag;
	t_list 	*list;
	char	*new_name;

	i = -1;
	list = NULL;
	while (++i < size)
	{
		new_name = ft_strjoin(name, mass[i]->content);
	
		if (check_if_dir(new_name) && ft_strcmp(".", mass[i]->content) && ft_strcmp("..", mass[i]->content))
		{
			printf("\n%s:\n", new_name);
			list = reading(info, new_name, &flag);
			next_stage(list, info, new_name);
			ft_strdel(&new_name);
		}
		
		ft_strdel(&new_name);
	}
	ft_strdel(&name);
}
