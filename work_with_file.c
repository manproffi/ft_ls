/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:45:55 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/28 14:45:56 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	work_with_file(t_list **mass, int size, t_info *info)
{
	info->fl_print_total = -1;
	choise_print_fun(info, mass, size, ft_strdup("./"));
}
