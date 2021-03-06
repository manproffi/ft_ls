/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_window_parameters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:38:41 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/19 21:38:48 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	read_window_parameters(t_info *info)
{
	struct winsize	ws;

	if ((ioctl(0, TIOCGWINSZ, &ws)) != -1)
	{
		info->w_window = ws.ws_col;
		info->h_window = ws.ws_row;
	}
	else
	{
		perror("ERROR");
		exit(1);
	}
}
