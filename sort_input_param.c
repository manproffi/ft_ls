/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 21:10:01 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/27 21:10:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	sort_part2(t_list *mass[3], t_info *info)
{
	t_list	**file;
	t_list	**link;
	t_list	**other;

	file = sort(mass[0], info, "./");
	link = sort(mass[1], info, "./");
	other = sort(mass[2], info, NULL);
	work_with_file(file, ft_lstsize(mass[0]), info);
	work_with_link(link, ft_lstsize(mass[1]), info);
	work_with_other(other, ft_lstsize(mass[2]), info);
	file ? free(file) : 0;
	link ? free(link) : 0;
	other ? free(other) : 0;
}
