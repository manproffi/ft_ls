/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:44:33 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/19 21:44:42 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	del_liaks(t_print **pr, t_list **mass)
{
	ft_strdel(&(*pr)->new_name);
	ft_strdel(&(*pr)->pw_name);
	ft_strdel(&(*pr)->gr_name);
	ft_strdel(&(*pr)->str_time);
	ft_strdel(&(*pr)->file_name);
	free(mass[0]->content);
	free(mass[0]);
	free(mass);
	if (*pr)
		free(*pr);
}

int		check_is_link(char const *name, t_info *info, int *flag)
{
	struct stat		p_stat;
	t_list			**mass;
	t_print			*pr;
	int				i;

	i = 0;
	lstat(name, &p_stat);
	if (name[ft_strlen(name) - 1] == '/')
		return (1);
	if (S_ISLNK(p_stat.st_mode) && (info->flags & 1) == 1)
	{
		*flag = 1;
		mass = (t_list**)malloc(sizeof(t_list*) * 1);
		mass[0] = ft_lstnew(name, ft_strlen(name) + 1);
		pr = (t_print*)malloc(sizeof(t_print) * 1);
		pr[0].new_name = ft_strdup(name);
		block_reading(pr, 0, mass);
		ft_printf("%c%s %d  %s %s  %d %s %s\n", pr[i].c, pr[i].buf,
				pr[i].h_link, pr[i].pw_name, pr[i].gr_name, pr[i].file_size,
				pr[i].str_time, pr[i].file_name);
		del_liaks(&pr, mass);
		return (0);
	}
	return (1);
}

t_list	*not_dir(char const *name, int *flag)
{
	char	*error;

	if (errno == EACCES)
	{
		error = ft_strjoin("ft_ls: ", name);
		perror(error);
		ft_strdel(&error);
		return (NULL);
	}
	*flag = 1;
	if (access(name, F_OK) != -1)
		return (ft_lstnew(name, ft_strlen(name) + 1));
	error = ft_strjoin("ft_ls: ", name);
	perror(error);
	ft_strdel(&error);
	return (NULL);
}

t_list	*reading(t_info *info, char const *name, int *flag)
{
	DIR				*p_dir;
	struct dirent	*p_dirent;
	t_list			*list;

	list = NULL;
	if (!check_is_link(name, info, flag))
		return (NULL);
	if ((p_dir = opendir(name)) == NULL)
		return (not_dir(name, flag));
	while ((p_dirent = readdir(p_dir)) != NULL)
	{
		if (((info->flags) & 4) == 0 && (p_dirent->d_name)[0] == '.')
			continue;
		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name,
					ft_strlen(p_dirent->d_name) + 1));
	}
	closedir(p_dir);
	return (list);
}
