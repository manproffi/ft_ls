/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:16:30 by sprotsen          #+#    #+#             */
/*   Updated: 2017/12/22 18:16:32 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "head_ls.h"

#include <sys/ioctl.h> //width terminal

void	insertSort(int size, t_list *mass[size]) 
{
	int i;
	int j;
	t_list * tmp;

	i = 1;
	while(i < size)
	{
		tmp = mass[i];
		j = i - 1;
		while(j >= 0 && ft_strcmp(mass[j]->content, tmp->content) > 0)
		{
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = tmp;
		++i;
	}
}

void	sort_lexicographical(t_list *list, int len)
{
	int		size;
	int		i;
	t_list	*mass[len];
	char 	*str;

	i = -1;
	while(list)
	{
		mass[++i] = list;
		list = list->next;
	}
	insertSort(len, mass);

	i = -1;
	while(++i < len)
	{
		str = mass[i]->content;
		if (str[0] != '.')
			printf("%-10s\t", str);
	}
	printf("\n");

}

void	del_list_list(t_list **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_memdel(&(*list)->content);
		free(*list);
	}
}

void	pr_list(t_list * lst)
{
	while(lst)
	{
		printf("%-s\t", lst->content);
		lst = lst->next;
	}
}


void	pure_command()
{
	DIR				*p_dir;
	struct dirent	*p_dirent;
	t_list			*list;

	if ((p_dir = opendir(".")) == NULL)
		return ;

	while ((p_dirent = readdir(p_dir)) != NULL)
	{
		ft_lstaddend(&list, ft_lstnew(p_dirent->d_name, ft_strlen(p_dirent->d_name) + 1));
	}
	sort_lexicographical(list, ft_lstsize(list));

	// pr_list(list);
	del_list_list(&list);
	closedir(p_dir);
}



void	read_width()
{
	unsigned short w = 0;
	unsigned short h = 0;

	struct winsize ws;
	if (!ioctl(0, TIOCGWINSZ, &ws))
		exit(-1);
	w = ws.ws_col;
	h = ws.ws_row;

	printf("%d\n %d\n", w, h);
}



int		main(int argc, char const *argv[])
{
	
	
	if (argc == 1)
		pure_command();
	
	
	// розкоментуй і буде помилка 
	printf("asdfasad\n");


	// read_width();
	
	// printf("%s\n", "dsafs");

	
    


 //    printf("%d\n", w.ws_row);
	// printf("%d\n", w.ws_col);



	// printf("%d\n", w.ws_xpixel);
	// printf("%d\n", w.ws_ypixel);

    // struct winsize w;
    // ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    // printf ("lines %d\n", w.ws_row);
    // printf ("columns %d\n", w.ws_col);
	// sleep(42);
	return (0);
}