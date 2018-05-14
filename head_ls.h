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


typedef struct 		s_info
{
	int				w_window;
	int				h_window;
	int				flags;
	// int				len_list;
}					t_info;


void		read_window_parameters(t_info * info);
int			parsing_command(int argc, char * argv[], t_info * info);
t_list	*	reading(t_info * info, char const * name, int *flag);
void		del_list_list(t_list **list);
void		print_column(t_info * info, t_list ** mass, int size);
void		work_with_parameters(int c_arg, int ac, char **av, t_info *info);
void	pr_list(t_list * lst);
t_list	**	sort(t_list * list, t_info * info);

void	next_stage(t_list *list, t_info * info, char * name);
char		get_filetype(mode_t m);
void	resursion(t_info *info, t_list **mass, int size, char *name);


#endif
