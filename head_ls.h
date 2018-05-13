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
# include "libft/libft.h"
# include "ft_printf/printhead.h"

typedef struct 		s_info
{
	int				w_window;
	int				h_window;
	int				flags;
}					t_info;


void	read_window_parameters(t_info * info);


#endif
