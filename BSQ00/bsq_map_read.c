/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_map_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:19:57 by yugao             #+#    #+#             */
/*   Updated: 2023/11/27 23:52:45 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


int	map_len(char *dir)
{
	int	map_id;
	int	map_count;
	int map_temp;

	map_id = open (dir, O_RDONLY);
	map_count = 0;
	if (!map_id)
	{
		ft_putstr ("READ DOCUMENT ERROR !\n");
		return (-1);
	}
	while (read (map_id, &map_temp, 1))
		map_count ++;
	close (map_id);
	return (map_count);
}

size map_size (char *str, char *str2)
{
	int		fila;
	int		columna;
	int		len;
	size	tamano;

	columna = 0;
	fila = 0;
	len = ft_strlen (str2);
	while (*str != '\0')
	{
		if(*str == '\n')
			fila ++;
		str ++;
	}
	tamano.y = fila + 1;
	tamano.x = len / (fila + 1);
	//if (length / tamano.x != 0)
		/////Error Map
	return (tamano);
}

char	*map_read(char *dir)
{
	char	*todo;
	char	temp;
	int		len;
	int		index;
	int		map_id;

	index =  0;
	len = map_len (dir);
	map_id = open (dir, O_RDONLY);
	if (!map_id)
	{
		ft_putstr ("READ DOCUMENT ERROR !\n");
		return (NULL);
	}
	todo = (char *) malloc (sizeof (char) * (len + 1));
	while (read (map_id, &temp, 1))
	{
		todo[index] = temp;
		index ++;
	}
	todo[index] = '\0';
	return (todo);
}

char	*map_to_matrix (char *str)
{
	char	*todo;
	int		index;
	char	temp;

	index = 0;
	todo = (char *) malloc (sizeof (char) * ft_strlen (str));
	while (*str)
	{
		if (*str == '.')
			temp = '1';
		else if (*str == 'o')
			temp = '0';
		
		if(*str != '\n')
		{
			todo[index] = temp;
			index ++;
		}
		str ++;
	}
	todo[index] = '\0';
	return (todo);
}

char	*map_to_oneline (char *str)
{
	char	*todo;
	int		index;
	char	temp;

	index = 0;
	todo = (char *) malloc (sizeof (char) * ft_strlen (str));
	while (*str)
	{
		temp = *str;
		if(*str != '\n')
		{
			todo[index] = temp;
			index ++;
		}
		str ++;
	}
	todo[index] = '\0';
	return (todo);
}