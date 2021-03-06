/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:40:15 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/19 20:26:28 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	clear_flag(int *flag)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		flag[i] = 0;
	}
}
