/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:02:32 by sprotsen          #+#    #+#             */
/*   Updated: 2018/01/02 20:02:33 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

t_list  *	reading(t_info * info, char const *name)
{
	DIR				*p_dir;
	struct dirent	*p_dirent;
	t_list			*list;

	list = NULL;
	if ((p_dir = opendir(name)) == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	while ((p_dirent = readdir(p_dir)) != NULL)
	{
		if (((info->flag) & 4) == 0 && (p_dirent->d_name)[0] == '.')
			continue;
		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name, ft_strlen(p_dirent->d_name) + 1));
	}
	// if (flag_print_name_folder)
	// 	printf("%s:\n", name);
	info->len_mass = ft_lstsize(list);
	// printf("%d\n", info->len_mass);
	closedir(p_dir);
	return list;


	// info->mass = sort_lexicographical(list, info);
	// pr_mass(info->len_mass, info->mass, info);
	// del_list_list(&list);
	// free(mass);
	
}