/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:42:20 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 18:42:22 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	insertSort(int size, t_list **mass) 
{
	int i;
	int j;
	t_list * tmp;

	i = 1;
	while(i < size)
	{
		tmp = mass[i];
		j = i - 1;
		while(j >= 0 && ft_strcmp(mass[j]->content, tmp->content) > 0)
		{
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = tmp;
		++i;
	}
}

t_list	**	sort(t_list * list, t_info * info)
{
	int			i;
	int 		len;
	t_list		**mass_for_sort;

	len = ft_lstsize(list);
	mass_for_sort = (t_list**)malloc(sizeof(t_list*) * len);
	i = -1;
	while (list)
	{
		mass_for_sort[++i] = list;
		list = list->next;
	}
	if ((info->flags & 8) == 0)
		insertSort(len, mass_for_sort);
	else
	{
		//TODO insert sort by time and may any sort 
		;
	}


	// printf("++++++++++TEST size %d\n", len);
	// i = -1;
	// while (++i < len)
	// {
	// 	printf("%s\n", (mass_for_sort[i])->content);
	// }
	return mass_for_sort;
}
