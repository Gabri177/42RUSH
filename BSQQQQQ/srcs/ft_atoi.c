/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:26:29 by yugao             #+#    #+#             */
/*   Updated: 2023/11/28 12:19:16 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_numero(char *letra)
{
	if (*letra >= '0' && *letra <= '9')
		return (1);
	else
		return (0);
}

int	is_positivo(char *str)
{
	int	simbolo;

	simbolo = 1;
	while (!is_numero(str) && *str != '\0')
	{
		if (*str == '-')
			simbolo *= -1;
		str ++;
	}
	return (simbolo);
}

int	times(int n)
{
	if (n == 1)
		return (1);
	else
		return (times(n - 1) * 10);
}

void	ajuste_pontero(char **str)
{
	while (!is_numero(*str) && **str != '\0')
		(*str)++;
}

int	ft_atoi(char *str)
{
	int	num_final;
	int	num;
	int	len;
	int	index;

	len = 0;
	index = 0;
	num = 0;
	num_final = is_positivo (str);
	ajuste_pontero (&str);
	while (is_numero (&str[index]) && str[index] != '\0')
		index ++;
	while (index >= 1)
	{
		num += (*str - '0') * times(index);
		index --;
		str ++;
	}
	return (num * num_final);
}
