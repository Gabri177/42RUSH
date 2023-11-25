/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_comprobation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:47:21 by snunez-z          #+#    #+#             */
/*   Updated: 2023/11/25 18:22:50 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_is_numeric(char	*str)
{
	int		index;
	char	ch;
	int		is_numeric;

	index = 0;
	while (str[index] != 0)
	{
		ch = str [index];
		is_numeric = (ch >= '0' && ch <= '9');
		if (!is_numeric)
		{
			return (0);
		}
		index++;
	}
	return (1);
}

int	file_exists(char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
	{
		return (0);
	}
	else
	{
		close (file);
		return (1);
	}
}

int	main(int argc,	char	**argv)
{
	if (argc == 1)
	{
		write(1, "Error", 5);
		return (0);
	}
	else if ((argc == 2) && (! ft_is_numeric (argv [1])))
	{
		write(1, "Error", 5);
		return (0);
	}
	else if ((argc > 2) && ((! ft_is_numeric (argv [2]))
			|| (! file_exists (argv [1]))))
	{
		write(1, "Error", 5);
		return (0);
	}
}
