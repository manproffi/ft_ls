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

# include <sys/ttycom.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <limits.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "libft/libft.h"
# include "ft_printf/printhead.h"
# include "head_ls_struct.h"

# define HALF_YEAR 15768000

void	read_window_parameters(t_info *info);
int		parsing_command(int argc, char *argv[], t_info *info);
t_list	*reading(t_info *info, char const *name, int *flag);
void	del_list_list(t_list **list);
void	print_column(t_info *info, t_list **mass, int size);
void	work_with_parameters(int c_arg, int ac, char **av, t_info *info);
void	pr_list(t_list *lst);
t_list	**sort(t_list *list, t_info *info, char *name);
void	next_stage(t_list *list, t_info *info, char *name, int *flag);
char	get_filetype(mode_t m);
void	resursion(t_info *info, t_list **mass, int size, char *name);
void	choise_print_fun(t_info *info, t_list **mass, int size, char *name);
void	flag_1(t_list **mass, int size);
void	flag_i(t_list **mass, int size, char *name);
void	flag_l(int size, t_list **mass, char const *name, t_info *info);
int		len_number(long long a);
char	get_extended_atribute(char *filename);
void	block_reading(t_print *pr, int i, t_list **mass);
void	final_print_l(int size, t_print *pr, t_info *info);
void	printing_part1(int len[5], blkcnt_t total, t_info *info, t_print *pr);
char	*check_time(struct stat *p_stat);
void	sort_part2(t_list *mass[3], t_info *info);
void	work_with_file(t_list **mass, int size, t_info *info);
void	work_with_link(t_list **mass, int size, t_info *info);
int		check_is_link(char const *name, t_info *info, int *flag);
void	work_with_other(t_list **mass, int size, t_info *info);
int		del_liaks(t_print **pr, t_list **mass);
int		check_is_link_flag_g(char const *name, t_info *info, int *flag);

#endif
