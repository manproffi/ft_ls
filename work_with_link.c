/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:11:34 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/28 16:11:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

int		check_is_link_flag_g(char const *name, t_info *info, int *flag)
{
	struct stat		p_stat;
	t_list			**mass;
	t_print			*pr;
	int				i;

	i = 0;
	lstat(name, &p_stat);
	if (name[ft_strlen(name) - 1] == '/')
		return (1);
	if (S_ISLNK(p_stat.st_mode) && (info->flags & 32) == 32)
	{
		*flag = 1;
		mass = (t_list**)malloc(sizeof(t_list*) * 1);
		mass[0] = ft_lstnew(name, ft_strlen(name) + 1);
		pr = (t_print*)malloc(sizeof(t_print) * 1);
		pr[0].new_name = ft_strdup(name);
		block_reading(pr, 0, mass);
		ft_printf("%c%s %d  %s  %d %s %s\n", pr[i].c, pr[i].buf,
				pr[i].h_link, pr[i].gr_name, pr[i].file_size,
				pr[i].str_time, pr[i].file_name);
		return (del_liaks(&pr, mass));
	}
	return (1);
}

void	work_with_link(t_list **mass, int size, t_info *info)
{
	t_list	*list;
	int		flag_file;
	int		i;

	flag_file = 0;
	list = NULL;
	i = -1;
	if ((info->flags & 1) == 1 || (info->flags & 32) == 32)
	{
		while (++i < size)
			if ((info->flags & 1) == 1)
				check_is_link(mass[i]->content, info, &flag_file);
			else
				check_is_link_flag_g(mass[i]->content, info, &flag_file);
	}
	else
	{
		while (++i < size)
		{
			list = reading(info, mass[i]->content, &flag_file);
			ft_printf("%s:\n", mass[i]->content);
			next_stage(list, info, mass[i]->content, &flag_file);
			i == size - 1 ? 0 : ft_printf("\n");
		}
	}
}
