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

int	 check_is_link(char const * name, t_info * info, int * flag)
{
	struct stat		p_stat;

	lstat(name, &p_stat);
	// perror("@@@@");
	t_list	**mass;
	t_print		*pr;

	if (name[ft_strlen(name) - 1] == '/')
		return (1);
	// printf("last falg===\n");
	if (S_ISLNK(p_stat.st_mode) && (info->flags & 1) == 1)
	{
		 // printf("+++++++LINK %s\n", name);
		*flag = 1;
		mass = (t_list**)malloc(sizeof(t_list*) * 1);
		mass[0] = ft_lstnew(name, ft_strlen(name) + 1);
		pr = (t_print*)malloc(sizeof(t_print) * 1);
		//flag_l(1, mass, name);
		//sleep(2);
		pr[0].new_name = ft_strdup(name);
		block_reading(1, pr, 0, mass);
		int i = 0;
		// perror("=+++");
		printf("%c%s %hu  %s %s  %lld %s %s\n", pr[i].c, pr[i].buf,  pr[i].h_link, pr[i].pw_name, pr[i].gr_name, pr[i].file_size, pr[i].str_time, pr[i].file_name);
		if (pr)
			free(pr);
		return (0);

	}
	// perror("asdfasd");

	return (1);
}



t_list	*	reading(t_info * info, char const * name, int *flag)
{
	DIR				*p_dir;
	struct dirent	*p_dirent;
	t_list			*list;
	char 			*error;

	list = NULL;
	// printf("flag+++++\n");
	if (!check_is_link(name, info, flag))
		return (NULL);
	if ((p_dir = opendir(name)) == NULL)
	{
		if (errno == EACCES)
		{
			error = ft_strjoin("ft_ls: ", name);
			perror(error);
			ft_strdel(&error);
			// printf(": Permission denied\n");
			return (NULL);
		}
		// sleep(10);
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

		//printf("%s %hhd\n", p_dirent->d_name, p_dirent->d_type);
		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name, ft_strlen(p_dirent->d_name) + 1));

	}
	closedir(p_dir);
	return list;
}
