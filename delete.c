/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:56:23 by sprotsen          #+#    #+#             */
/*   Updated: 2018/05/13 15:56:27 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	del_list_list(t_list **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_memdel(&(*list)->content);
		free(*list);
	}
}
