/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:05:45 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 14:06:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_LS_H
# define HEAD_LS_H

# include <stdio.h>
# include <sys/ttycom.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <limits.h>
# include <dirent.h>
# include "libft/libft.h"
# include "ft_printf/printhead.h"

# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h> // owner 
# include <time.h> //ctime
# include <sys/xattr.h>
# include <sys/acl.h>


typedef struct 		s_info
{
	int				w_window;
	int				h_window;
	int				flags;
	// int				len_list;
}					t_info;

typedef	struct 		s_print
{
	char			*new_name;
	char			c;
	char			buf[10];
	nlink_t			h_link;
	struct passwd 	*pw;
	struct group  	*gr;
	off_t			file_size;
	char 			*str_time;
	char			*file_name;
	blkcnt_t		total;
	char			buffer[256];
}					t_print;


void		read_window_parameters(t_info * info);
int			parsing_command(int argc, char * argv[], t_info * info);
t_list	*	reading(t_info * info, char const * name, int *flag);
void		del_list_list(t_list **list);
void		print_column(t_info * info, t_list ** mass, int size);
void		work_with_parameters(int c_arg, int ac, char **av, t_info *info);
void	pr_list(t_list * lst);
t_list	**	sort(t_list * list, t_info * info, char * name);

void	next_stage(t_list *list, t_info * info, char * name);
char		get_filetype(mode_t m);
void	resursion(t_info *info, t_list **mass, int size, char *name);
void 	choise_print_fun(t_info *info, t_list **mass, int size, char *name);

void	flag_1(t_list **mass, int size);
void	flag_i(t_list **mass, int size, char *name);


void	flag_l(int size, t_list **mass, char const * name);
int len_number(long long a);

#endif
