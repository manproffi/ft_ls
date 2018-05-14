/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 20:06:55 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/14 20:06:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

int		check_if_dir(char * name)
{
	 struct stat  p_stat;

	if (lstat(name, &p_stat) == 0 && S_ISDIR(p_stat.st_mode))
		return 1;
	
	 // printf("======= %s\n", name);
	 // printf("======= %X\n", p_stat.st_mode & S_IFMT);
	 // printf("%d\n", p_stat.st_mode & S_IFMT);
	 // printf("%d\n", S_ISDIR(p_stat.st_mode));
	// switch (p_stat.st_mode & S_IFMT) {
 //    	case S_IFBLK:  printf("block device\n");            break;
 //    	case S_IFCHR:  printf("character device\n");        break;
 //    	case S_IFLNK:  printf("symlink\n");                 break;
 //    	case S_IFDIR:  printf("directory\n");               break;
 //    	case S_IFIFO:  printf("FIFO/pipe\n");               break;
 //    	case S_IFREG:  printf("regular file\n");            break;
 //    	case S_IFSOCK: printf("socket\n");                  break;
 //    	default:       printf("unknown?\n");                break;
 //    }
	// NO_FOLLOW;

	// printf("%d\t%s\n", S_ISLNK(p_stat.st_mode)	,	"symbolic link");
	// printf("%d\t%s\n", S_ISREG(p_stat.st_mode)	,	"regular file");
	// printf("%d\t%s\n", S_ISDIR(p_stat.st_mode)	,	"directory");
	// printf("%d\t%s\n", S_ISBLK(p_stat.st_mode)	,	"block special");
	// printf("%d\t%s\n", S_ISCHR(p_stat.st_mode)	,	"char special");
	// printf("%d\t%s\n", S_ISFIFO(p_stat.st_mode)	,	"fifo or socket");
	// printf("%d\t%s\n", S_ISSOCK(p_stat.st_mode) ,		"socket");
	// printf("%d\t%s\n", S_ISWHT(p_stat.st_mode)	,		"OBSOLETE: whiteout");

	

	return 0;


}


void	resursion(t_info *info, t_list **mass, int size, char *name)
{
	int		i;
	int		flag;
	t_list 	*list;
	char	*new_name;

	i = -1;
	list = NULL;
	while (++i < size)
	{
		new_name = ft_strjoin(name, mass[i]->content);
	
		if (check_if_dir(new_name))
		{
			printf("\n%s:\n", new_name);
			list = reading(info, new_name, &flag);
			next_stage(list, info, new_name);
			ft_strdel(&new_name);
		}
		
		ft_strdel(&new_name);
	}
	ft_strdel(&name);
}
