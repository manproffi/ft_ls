/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choise_print_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:53:08 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/15 20:53:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void choise_print_fun(t_info *info, t_list **mass, int size, char *name)
{
		printf(RED"choise_print_fun\n"RESET);
	if ((info->flags & 1) == 1)
		flag_l(size, mass, name);
	else if ((info->flags & 16) == 16)
		flag_1(mass, size);
	else if ((info->flags & 32) == 32)
		printf("%s\n", "ggggg");
	else if ((info->flags & 64) == 64)
		flag_i(mass, size, name);
	else
		print_column(info, mass, size);
	ft_strdel(&name);
}

