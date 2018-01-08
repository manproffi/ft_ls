/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 21:13:37 by sprotsen          #+#    #+#             */
/*   Updated: 2018/01/02 21:13:40 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

// t_list  *	reading_rec(t_info * info, char const *name)
// {
// 	DIR				*p_dir;
// 	struct dirent	*p_dirent;
// 	t_list			*list;

// 	list = NULL;
// 	if ((p_dir = opendir(name)) == NULL)
// 	{
// 		perror("ERROR");
// 		exit(1);
// 	}
// 	while ((p_dirent = readdir(p_dir)) != NULL)
// 	{
// 		if (((info->flag) & 4) == 0 && (p_dirent->d_name)[0] == '.')
// 			continue;
// 		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name, ft_strlen(p_dirent->d_name) + 1));
// 	}
// 	// if (flag_print_name_folder)
// 	// 	printf("%s:\n", name);
// 	info->len_mass = ft_lstsize(list);
// 	// printf("%d\n", info->len_mass);
// 	closedir(p_dir);
// 	return list;


// 	// info->mass = sort_lexicographical(list, info);
// 	// pr_mass(info->len_mass, info->mass, info);
// 	// del_list_list(&list);
// 	// free(mass);
	
// }



int		check_if_dir(char * name)
{
	struct stat  p_stat;
	stat(name, &p_stat);
	ft_strdel(&name);
	if (get_filetype(p_stat.st_mode) == 'd')
		return 1;
	// printf("%c\n", get_filetype(p_stat.st_mode));
	return 0;


}



void	recursion(char const * name, t_info * old_info)
{
	t_list 		*list;
	t_list		**mass;
	int			i;
	char		*new_name;

	t_info 		info;

	info.len_mass = old_info->len_mass;
	info.w = old_info->w;
	info.h = old_info->h;
	info.flag = old_info->flag;

	// printf("total: \n");
	// printf("recursin\n");
	list = reading(&info, name);
	new_name = ft_strjoin(name, "/");
	// printf("%p\n", new_name);
	mass = sort_lexicographical(list, &info, new_name);

	// printf("%s:\n", name);
	// struct stat  p_stat;
	// stat(new_name, &p_stat);
	// blkcnt_t a;
	// a = p_stat.st_blocks;
	// printf("a: %lld\n", a);
	// printf(RED"total: %s %lld\n"RESET, name, p_stat.st_blocks );
	// printf("%d\n", info.flag & 1 );
	if (info.flag & 1)
		flag_l(info.len_mass, mass, new_name);
	else
		pr_mass(info.len_mass, mass, &info);
	// pr_list(list);
	// printf("%d\n", info->max_len);
	// printf("%s\n", name);
	
	i = -1;
	while(++i < info.len_mass)
	{
		if ((((char*)(mass[i]->content))[0] != '.') && check_if_dir(ft_strjoin(new_name, mass[i]->content)))
		{
			char * new_name2 = ft_strjoin(new_name, mass[i]->content);
			printf("\n%s:\n", new_name2);
			recursion(new_name2, &info);
			ft_strdel(&new_name2);
		}
	}
		
	del_list_list(&list);
	ft_strdel(&new_name);
	free(mass);
	// printf("asdfasdfasd\n");


}





void	work_with_flags(int argc, int i, t_info * info, char const *argv[])
{
	// printf("argc: %d\n",  argc);
	// printf("i   : %d\n",  i);
	// printf("%s\n", argv[i]);

	t_list	*list;
	int		flag;

	// printf("%d\n", info->flag );

	flag = 0;
	while(i < argc)
	{
		
		if (argc - i != 1 || flag == 1)
			printf("%s:\n", argv[i]);
		if (((info->flag) & 2) != 0)
		{
			recursion(argv[i], info);
		}
		++i;
		if (argc - i)
		{
			flag = 1;
			printf("\n");
		}
		// printf("R:%d\n", (info->flag) & 1 << 0);
		// printf("R:%d\n", (info->flag) & 1 << 1);
		// printf("R:%d\n", (info->flag) & 1 << 2);
		// printf("R:%d\n", (info->flag) & 1 << 3);
		// printf("R:%d\n", (info->flag) & 1 << 4);
		// printf("R:%d\n", (info->flag) & 1 << 5);
		// printf("R:%d\n", (info->flag) & 1 << 6);


		

		// int a = ((info->flag) & 2);
		// printf("%d\n", a);


		// if (argc - i != 1 || flag == 1)
		// 	printf("%s:\n", argv[i]);
		// // printf("%d\n", info->len_mass);
		// list = reading(info, argv[i]);
		// // printf("%d\n", info->len_mass);
		// info->mass = sort_lexicographical(list, info);
		// pr_mass(info->len_mass, info->mass, info);
		// if (((info->flag) & 2) == 1)
		// 	recurtion(argv);
		// del_list_list(&list);
		// free(info->mass);
		// ++i;

		// if (argc - i)
		// {
		// 	flag = 1;
		// 	printf("\n");
		// }
		// printf("%d\n", info->len_mass);
	}
	

}
