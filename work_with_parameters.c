/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:25:28 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 17:25:34 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	next_stage(t_list *list, t_info *info, char *name, int *flag)
{
	t_list	**tmp;
	char	*str_name;

	if (name[ft_strlen(name) - 1] == '/')
		str_name = ft_strdup(name);
	else if (*flag)
	{
		*flag = 0;
		str_name = ft_strdup(name);
	}
	else
		str_name = ft_strjoin(name, "/");
	tmp = sort(list, info, name);
	choise_print_fun(info, tmp, ft_lstsize(list), str_name);
	if ((info->flags & 2) == 2)
		resursion(info, tmp, ft_lstsize(list), ft_strjoin(name, "/"));
	del_list_list(&list);
	if (tmp)
		free(tmp);
}

/*
** file - [0]
** link - [1]
** other - [2]
*/

int		check_error(char *name, int *c_a)
{
	char	*error;

	if (access(name, F_OK) == -1)
	{
		error = ft_strjoin("ft_ls: ", name);
		perror(error);
		ft_strdel(&error);
		*c_a += 1;
		return (1);
	}
	return (0);
}

void	sort_input(int c_a, int ac, char **av, t_info *info)
{
	struct stat		p_stat;
	char			c;
	t_list			*mass[3];

	mass[0] = NULL;
	mass[1] = NULL;
	mass[2] = NULL;
	while (c_a < ac)
	{
		if (check_error(av[c_a], &c_a))
			continue ;
		lstat(av[c_a], &p_stat);
		c = get_filetype(p_stat.st_mode);
		if (c == 'l')
			ft_lstaddend(&mass[1], ft_lstnew(av[c_a], ft_strlen(av[c_a]) + 1));
		else if (c == '-')
			ft_lstaddend(&mass[0], ft_lstnew(av[c_a], ft_strlen(av[c_a]) + 1));
		else
			ft_lstaddend(&mass[2], ft_lstnew(av[c_a], ft_strlen(av[c_a]) + 1));
		++c_a;
	}
	sort_part2(mass, info);
	del_list_list(&mass[0]);
	del_list_list(&mass[1]);
	del_list_list(&mass[2]);
}

void	work_with_parameters(int c_arg, int ac, char **av, t_info *info)
{
	t_list	*list;
	int		marker_for_address;
	int		flag_file;

	flag_file = 0;
	if (ac == c_arg)
	{
		list = reading(info, ".", &flag_file);
		next_stage(list, info, ".", &flag_file);
		return ;
	}
	marker_for_address = ac - c_arg;
	if (marker_for_address > 1)
		sort_input(c_arg, ac, av, info);
	else
	{
		list = reading(info, av[c_arg], &flag_file);
		if (!list)
			return ;
		next_stage(list, info, av[c_arg], &flag_file);
	}
}
