/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:26:36 by yugao             #+#    #+#             */
/*   Updated: 2023/11/28 12:11:10 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void    ft_putstr(char *str)
{
    while (*str)
    {
        write (1, str, 1);
        str ++;
    }
}

int ft_strlen(char *str)
{
    int index;

    index = 0;
    while (str[index] != '\0')
        index ++;
    return (index);
}

char    ft_min (char l1, char l2, char l3)
{
    int a;
    int b;
    int c;
    int min;

    a = l1 - '0';
    b = l2 - '0';
    c = l3 - '0';
    if (a <= b && a <= c)
        min = a; 
    if (b <= a && b <= c)
        min = b; 
    if (c <= b && c <= a)
        min = c; 
    return ((char)(min + 1 + '0'));
}

int ft_isnumero (char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}