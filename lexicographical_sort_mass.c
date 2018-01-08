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

int compere(char * a , char * b)
{
	struct stat  aa;
	struct stat  bb;
	stat(a, &aa);
	stat(b, &bb);
	int res;

	// printf("%lu\n", aa.st_mtimespec.tv_sec);
	// printf("%lu\n", bb.st_mtimespec.tv_sec);


	if (aa.st_mtimespec.tv_sec == bb.st_mtimespec.tv_sec)
		res = ft_strcmp(a, b);
	else if (aa.st_mtimespec.tv_sec < bb.st_mtimespec.tv_sec)
		res = 1;
	else
		res = 0;
	ft_strdel(&a);
	ft_strdel(&b);
	return res;

	// aa.st_mtimespec.tv_sec
	// bb.st_mtimespec.tv_sec
}

static void	sort_by_time_modified(int size, t_list **mass, const char * name) 
{
	int i;
	int j;
	t_list * tmp;

	i = 1;
	while(i < size)
	{
		tmp = mass[i];
		j = i - 1;
		while(j >= 0 && compere(ft_strjoin(name, mass[j]->content), ft_strjoin(name, tmp->content)) > 0)
		{
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = tmp;
		++i;
	}
}




t_list  **	sort_lexicographical(t_list *list, t_info * info, const char * name)
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
	if ((info->flag & 8) == 0)
		insertSort(info->len_mass, mass);
	else
		sort_by_time_modified(info->len_mass, mass, name);
	return mass;
}