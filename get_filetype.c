/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filetype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:04:49 by sprotsen          #+#    #+#             */
/*   Updated: 2018/01/08 16:04:52 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

char		get_filetype(mode_t m)
{
	char type;

	if ((m & 0160000) == 0160000)
		type = 'w';
	else if ((m & 0140000) == 0140000)
		type = 's';
	else if ((m & 0120000) == 0120000)
		type = 'l';
	else if ((m & 0100000) == 0100000)
		type = '-';
	else if ((m & 0060000) == 0060000)
		type = 'b';
	else if ((m & 0040000) == 0040000)
		type = 'd';
	else if ((m & 0020000) == 0020000)
		type = 'c';
	else if ((m & 0010000) == 0010000)
		type = 'p';
	else
		type = 'x';
	return (type);
}