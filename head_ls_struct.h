/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_ls_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:26:47 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/19 21:28:08 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_LS_STRUCT_H
# define HEAD_LS_STRUCT_H

typedef struct		s_info
{
	int				w_window;
	int				h_window;
	int				flags;
	int				fl_print_total;
}					t_info;

typedef	struct		s_print
{
	char			*new_name;
	char			c;
	char			buf[11];
	nlink_t			h_link;
	char			*pw_name;
	char			*gr_name;
	off_t			file_size;
	char			*str_time;
	char			*file_name;
	unsigned int	maj;
	unsigned int	min;
	blkcnt_t		total;
}					t_print;

#endif
