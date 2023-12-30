/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_pd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:06:56 by yugao             #+#    #+#             */
/*   Updated: 2023/11/29 14:09:05 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_post	pd_renova(int columna, int fila, int len)
{
	t_post	p;

	p.x = columna;
	p.y = fila;
	p.len = len;
	return (p);
}

t_post	pd_matrix(char *c, int x, int y)
{
	int		columna;
	int		fila;
	char	min;
	char	max;
	t_post	p;

	columna = 1;
	fila = 1;
	max = 1;
	while (fila < y)
	{
		while (columna < x)
		{
			if (c[matrix_index(x, columna, fila)] == '1')
			{
				min = ft_min (c[matrix_index (x, columna - 1, fila)], c[matrix_index (x, columna, fila - 1)], c[matrix_index (x, columna - 1, fila - 1)]);
				c[matrix_index (x, columna, fila)] = min;
				if (max < (int)(c[matrix_index (x, columna, fila)] - '0'))
				{
					max = min - '0';
					p = pd_renova (columna, fila, max);
				}
			}
			columna ++;
		}
		columna = 1;
		fila ++;
	}
	return (p);
}

t_post	pd_p_upperleft(t_post lower_right)
{
	t_post	ur;

	ur.x = lower_right.x - lower_right.len + 1;
	ur.y = lower_right.y - lower_right.len + 1;
	ur.len = lower_right.len;
	return (ur);
}
