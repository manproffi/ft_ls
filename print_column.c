/* ************************************************************************* */
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   print_column.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2018/05/13 19:49:35 by sprotsen          #+#    #+#            */
/*   Updated: 2018/05/13 19:49:51 by sprotsen         ###   ########.fr      */
/*                                                                           */
/* ************************************************************************* */

#include "head_ls.h"

int		max_length(t_list **mass, int size)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (++i < size)
		if (mass[i]->content_size > len)
			len = mass[i]->content_size;
	return (len);
}

void	print_column(t_info *info, t_list **mass, int size)
{
	int		column;
	int		row;
	int		i;
	int		j;
	int		max_len;

	i = -1;
	max_len = max_length(mass, size);
	column = info->w_window / (max_len + 4);
	if (size % column != 0)
		row = 1;
	else
		row = 0;
	row += size / column;
	while (++i < row)
	{
		j = i;
		while (j < column * row)
		{
			if (j < size)
				ft_printf("%-*s\t", max_len, mass[j]->content);
			j += row;
		}
		ft_printf("\n");
	}
}

