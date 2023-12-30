/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:47 by yugao             #+#    #+#             */
/*   Updated: 2023/11/29 14:11:22 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int arc, char **arg)
{
	char	*str_ori;
	char	*str_mtrx_ori;
	char	*str01;
	t_size	tamano;
	t_post	p;
	t_info	info;
	int		len;
	int		index;

	index = 1;
	len = arc;
	if (arc == 1)
	{
		ft_putstr ("NO INFORMACION DE MAP !!!\n");
		return (0);
	}
	while (index < arc)
	{
		str_ori = map_read (arg[index]);
		map_dato (&info, str_ori);
		str_mtrx_ori = map_to_oneline (str_ori + info.ini_posicion);
		str01 = map_to_matrix(str_ori + info.ini_posicion, info);
		tamano = map_t_size (str_ori, str01);
		if (tamano.y != info.fila || tamano.y == 0)
		{
			ft_putstr ("ERROR FORMAT OF MAP !!!\n");
			index ++;
			continue ;
		}
		p = pd_matrix (str01, tamano.x, tamano.y);
		p = pd_p_upperleft(p);
		matrix_dibujar (p, tamano, str_mtrx_ori, info.llena);
		matrix_output (tamano.x, str_mtrx_ori);
		index ++;
		ft_putstr ("\n");
	}
	return (0);
}
