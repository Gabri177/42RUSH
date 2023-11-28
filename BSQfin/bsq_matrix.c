/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:34:30 by yugao             #+#    #+#             */
/*   Updated: 2023/11/28 13:42:47 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	matrix_index (int max_x, int x, int y)
{
	return (y * max_x + x);
}

size matrix_position (int max_x, int index) //还没有测试
{
	size tamano;

	tamano.x = index % max_x;
	tamano.y = (index - tamano.x) / max_x;
	return (tamano);
}

void	matrix_output (int max_x, char *str)
{
	int	index;
	char	salto;

	salto = '\n';
	index = 0;
	while (*str)
	{
		if (index == max_x)
		{
			index = 0;
			write (1, &salto, 1);
		}
		write (1, str, 1);
		index ++;
		str ++;
	}
}

void	matrix_dibujar (position p, size tamano, char *str, char llena)
{
	int	index_x;
	int	index_y;

	index_x = p.x;
	index_y = p.y;
	while (index_y < p.len + p.y)
	{
		while (index_x < p.len + p.x)
		{
			str[matrix_index(tamano.x, index_x, index_y)] = llena;
			index_x ++;
		}
		index_x = p.x;
		index_y ++;
	}
}