/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pure_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:31:51 by sprotsen          #+#    #+#             */
/*   Updated: 2017/12/25 17:31:53 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

// void	pure_command(t_info * info)
// {
// 	DIR				*p_dir;
// 	struct dirent	*p_dirent;
// 	t_list			*list = NULL;
// 	t_list			**mass;
// 	int				len;

// 	if ((p_dir = opendir(".")) == NULL)
// 	{
// 		perror("ERROR");
// 		exit(1);
// 	}
// 	while ((p_dirent = readdir(p_dir)) != NULL)
// 	{
// 		if ((p_dirent->d_name)[0] == '.')
// 			continue;
// 		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name, ft_strlen(p_dirent->d_name) + 1));
// 	}
// 	len = ft_lstsize(list);
// 	mass = sort_lexicographical(list, len, info);
// 	pr_mass(len, mass, info);
// 	// pr_list(list);
// 	del_list_list(&list);
// 	free(mass);
// 	closedir(p_dir);
// }