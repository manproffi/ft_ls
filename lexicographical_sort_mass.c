/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_sort_mass.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:35:46 by sprotsen          #+#    #+#             */
/*   Updated: 2017/12/25 17:35:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

static void	insertSort(int size, t_list **mass) 
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

t_list  **	sort_lexicographical(t_list *list, t_info * info)
{
	int		size;
	int		i;
	t_list	**mass;

	mass = (t_list**)malloc(sizeof(t_list*) * info->len_mass);
	i = -1;
	info->max_len = 0;
	while(list)
	{
		mass[++i] = list;
		if (list->content_size > (size_t)info->max_len)
			info->max_len = list->content_size;
		list = list->next;
	}
	insertSort(info->len_mass, mass);
	return mass;
}