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

	type = ' ';

	type = S_ISBLK(m) ? 'b' : type;
	type = S_ISCHR(m) ? 'c' : type;
	type = S_ISDIR(m) ? 'd' : type;
	type = S_ISFIFO(m) ? 'p' : type;
	type = S_ISREG(m) ? '-' : type;
	type = S_ISLNK(m) ? 'l' : type;
	type = S_ISSOCK(m) ? 's' : type;

	return type;
}