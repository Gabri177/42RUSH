/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:41 by yugao             #+#    #+#             */
/*   Updated: 2023/11/27 23:50:21 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct size
{
    int x;
    int y;
} size;

typedef struct position
{
    int x;
    int y;
    int len;
} position;

//---------------ft_str.c-------------------
void        ft_putstr (char *str);
int         ft_strlen(char *str);
char        ft_min (char l1, char l2, char l3);
//---------------ft_str.c-------------------

//-------------bsq_map_read.c---------------
int		    map_len(char *dir);
char	    *map_read(char *dir);
char	    *map_to_matrix (char *str);
size        map_size (char *str, char* str2);
//-------------bsq_map_read.c---------------

//-------------bsq_matrix.c-----------------
size        matrix_position (int max_x, int max_y, int index);
int         matrix_index (int max_x, int max_y,int x, int y);
void	    matrix_output (int max_x, char *str);
void	    matrix_dibujar (position p, size tamano, char *str);
//-------------bsq_matrix.c-----------------

//-------------bsq_pd.c---------------------
position    pd_matrix (char *c, int x, int y);
//-------------bsq_pd.c---------------------

# include "ft_str.c"
# include "bsq_map_read.c"
# include "bsq_matrix.c"
# include "bsq_pd.c"

#endif