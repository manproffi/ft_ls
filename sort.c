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

int compere(char * a , char * b)
{
	struct stat  aa;
	struct stat  bb;
	lstat(a, &aa);
	lstat(b, &bb);
	int res;


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
	while (i < size)
	{
		tmp = mass[i];
		j = i - 1;
		while (j >= 0 && compere(ft_strjoin(name, mass[j]->content), ft_strjoin(name, tmp->content)) > 0)
		{
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = tmp;
		++i;
	}
}

t_list	**	sort(t_list * list, t_info * info, char * name)
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
	if ((info->flags & 8) == 8)
	{
		// sleep(5);
		sort_by_time_modified(len, mass_for_sort, name);
	}
	else
	{
		// sleep(5);
		insertSort(len, mass_for_sort);
	}

	// int j = -1;
	// while (++j < len)
	// 	printf(RED"%s\n"RESET, mass_for_sort[j]->content);



	// printf("++++++++++TEST size %d\n", len);
	// i = -1;
	// while (++i < len)
	// {
	// 	printf("%s\n", (mass_for_sort[i])->content);
	// }
	return mass_for_sort;
}
