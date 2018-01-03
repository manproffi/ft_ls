/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mass.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:37:56 by sprotsen          #+#    #+#             */
/*   Updated: 2017/12/23 12:37:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_ls.h"

void	pr_mass(int size, t_list **mass, t_info * info)
{
	
	int		column;
	int		row;

	column = info->w / (info->max_len + 4);
	
	if (size % column != 0)
		row = 1;
	else
		row = 0;
	row += size / column;


	
	// printf("%d\n", column);
	// printf("%d\n", row);
	// printf("%d\n", size);

	// printf("%d\t %d\n", info->w, info->max_len);


	int		i;
	int		j;

	char 	*str;
	i = -1;

	while(++i < row)
	{
		j = i;
		while (j < column * row)
		{
			if (j < size)
			{
				str = mass[j]->content;
				ft_printf("%-*s\t", info->max_len, str);
			}
			j += row;
		}
		ft_printf("\n");
	}
}
