/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:51:56 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/19 21:52:06 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	reverse_sort(int size, t_list **mass)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (++i < size / 2)
	{
		tmp = mass[i];
		mass[i] = mass[size - 1 - i];
		mass[size - 1 - i] = tmp;
	}
}

void	insert_sort(int size, t_list **mass)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	while (i < size)
	{
		tmp = mass[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(mass[j]->content, tmp->content) > 0)
		{
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = tmp;
		++i;
	}
}

int		compere(char *a, char *b)
{
	struct stat		aa;
	struct stat		bb;
	int				res;

	lstat(a, &aa);
	lstat(b, &bb);
	if (aa.st_mtimespec.tv_sec == bb.st_mtimespec.tv_sec)
		res = ft_strcmp(a, b);
	else if (aa.st_mtimespec.tv_sec < bb.st_mtimespec.tv_sec)
		res = 1;
	else
		res = 0;
	ft_strdel(&a);
	ft_strdel(&b);
	return (res);
}

void	sort_by_time_modified(int size, t_list **mass, char *name)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	while (i < size)
	{
		tmp = mass[i];
		j = i - 1;
		while (j >= 0 && compere(ft_strjoin(name, mass[j]->content),
					ft_strjoin(name, tmp->content)) > 0)
		{
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = tmp;
		++i;
	}
	ft_strdel(&name);
}

t_list	**sort(t_list *list, t_info *info, char *name)
{
	int			i;
	int			len;
	t_list		**mass_for_sort;

	len = ft_lstsize(list);
	if (len == 0)
		return (NULL);
	mass_for_sort = (t_list**)malloc(sizeof(t_list*) * len);
	i = -1;
	while (list)
	{
		mass_for_sort[++i] = list;
		list = list->next;
	}
	if ((info->flags & 8) == 8)
		sort_by_time_modified(len, mass_for_sort, ft_strjoin(name, "/"));
	else
		insert_sort(len, mass_for_sort);
	if (((info->flags & 128) == 128))
		reverse_sort(len, mass_for_sort);
	return (mass_for_sort);
}
