/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 21:10:01 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/27 21:10:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

int		find_in_mass(char *name, t_list *list)
{
	while (list)
	{
		if (!ft_strcmp(name, list->content))
			return (1);
		list = list->next;
	}
	return (0);
}

void	choise_fun(t_list *list, t_info *info, t_list *mass[3])
{
	t_list	**new_mass;
	int		len_mass;
	int		i;

	new_mass = sort(list, info, "./");
	len_mass = ft_lstsize(mass[0]) + ft_lstsize(mass[1]) + ft_lstsize(mass[2]);
	i = -1;
	while (++i < len_mass)
	{
		if (find_in_mass(new_mass[i]->content, mass[0]))
			work_with_file(&new_mass[i], 1, info);
		else if (find_in_mass(new_mass[i]->content, mass[1]))
			work_with_link(&new_mass[i], 1, info);
		else
			work_with_other(&new_mass[i], 1, info);
		i == len_mass - 1 ? 0 : ft_printf("\n");
	}
	new_mass ? free(new_mass) : 0;
}

void	add_file_link_other(t_list *mass[3], t_info *info)
{
	t_list		*list;
	t_list		*tmp;
	int			i;

	i = -1;
	list = NULL;
	while (++i < 3)
	{
		tmp = mass[i];
		while (tmp)
		{
			ft_lstaddend(&list, ft_lstnew(tmp->content, tmp->content_size + 1));
			tmp = tmp->next;
		}
	}
	choise_fun(list, info, mass);
	del_list_list(&list);
}

void	sort_part2(t_list *mass[3], t_info *info)
{
	t_list	**file;
	t_list	**link;
	t_list	**other;

	file = NULL;
	link = NULL;
	other = NULL;
	file = sort(mass[0], info, "./");
	link = sort(mass[1], info, "./");
	other = sort(mass[2], info, "./");
	work_with_file(file, ft_lstsize(mass[0]), info);
	work_with_link(link, ft_lstsize(mass[1]), info);
	work_with_other(other, ft_lstsize(mass[2]), info);
	file ? free(file) : 0;
	link ? free(link) : 0;
	other ? free(other) : 0;
}
