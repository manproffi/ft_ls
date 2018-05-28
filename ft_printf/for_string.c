/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:29:24 by sprotsen          #+#    #+#             */
/*   Updated: 2017/02/13 19:29:27 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhead.h"

void	pr_string(size_t len, size_t *res, char *str, int *fl)
{
	size_t	i;

	i = 0;
	fl[6] > 0 ? fl[4] = 0 : 0;
	if (len == 0)
		return ;
	if (fl[6] > 0 && fl[6] < (int)len)
		len = fl[6];
	write(1, str, len);
	*res += len;
}

int		pr_null(size_t *res, int *fl)
{
	for_string("(null)", res, fl);
	return (0);
}

void	pr_part_string(void *point, int *fl, size_t *res, size_t len)
{
	int		pr;

	pr = fl[5] - (((fl[6] < (int)len) && fl[6] != 0) ? fl[6] : (int)len);
	fl[4] == 1 ? pr_space_null(pr, res, '0') : pr_space_null(pr, res, ' ');
	pr_string(len, res, (char*)point, fl);
}

int		for_string(void *point, size_t *res, int *fl)
{
	size_t		len;
	int			pr;

	if (fl[5] == -996)
		fl[5] = (int)point;
	point != NULL ? len = ft_strlen_printf((char *)point) : 0;
	if (fl[6] == -1)
	{
		fl[4] == 1 ? PSN(fl[5], res, '0') : PSN(fl[5], res, ' ');
		return (0);
	}
	if ((char*)point == NULL)
		return (pr_null(res, fl));
	if (fl[5] > 0 && fl[3] == 0)
		pr_part_string(point, fl, res, len);
	else if (fl[5] > 0 && fl[3] == 1)
	{
		pr_string(len, res, (char*)point, fl);
		pr = fl[5] - (((fl[6] < (int)len) && fl[6] != 0) ? fl[6] : (int)len);
		pr_space_null(pr, res, ' ');
		return (0);
	}
	else
		pr_string(len, res, (char*)point, fl);
	return (0);
}
