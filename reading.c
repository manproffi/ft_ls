/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:38:41 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 15:38:43 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

#include <unistd.h>

t_list	*	reading(t_info * info, char const * name, int *flag)
{
	DIR				*p_dir;
	struct dirent	*p_dirent;
	t_list			*list;
	char 			*error;

	list = NULL;
	if ((p_dir = opendir(name)) == NULL)
	{
		*flag = 1;
		if (access(name, F_OK) != -1)
			return ft_lstnew(name, ft_strlen(name) + 1);
		error = ft_strjoin("ft_ls: ", name);
		perror(error);
		ft_strdel(&error);
		return NULL;
	}
	while ((p_dirent = readdir(p_dir)) != NULL)
	{
		if (((info->flags) & 4) == 0 && (p_dirent->d_name)[0] == '.')
			continue;
		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name, ft_strlen(p_dirent->d_name) + 1));

	}
	closedir(p_dir);
	return list;
}
