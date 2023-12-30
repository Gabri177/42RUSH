/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:41 by yugao             #+#    #+#             */
/*   Updated: 2023/11/28 13:42:18 by yugao            ###   ########.fr       */
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

typedef struct info_doc
{
    char    *ori;
    char    vacio;
    char    obstaculo;
    char    llena;
    int     fila;
    int     ini_posicion;
}info_doc;


//---------------ft_str.c-------------------
void        ft_putstr (char *str);
int         ft_strlen(char *str);
char        ft_min (char l1, char l2, char l3);
int         ft_isnumero (char c);
//---------------ft_str.c-------------------

//-------------bsq_map_read.c---------------
int		    map_len(char *dir);
char	    *map_read(char *dir);
char	    *map_to_matrix (char *str, info_doc info);
size        map_size (char *str, char* str2);
//-------------bsq_map_read.c---------------

//-------------bsq_matrix.c-----------------
int         matrix_index (int max_x, int x, int y);
void	    matrix_output (int max_x, char *str);
void	    matrix_dibujar (position p, size tamano, char *str, char llena);
//-------------bsq_matrix.c-----------------

//-------------bsq_pd.c---------------------
position    pd_matrix (char *c, int x, int y);
//-------------bsq_pd.c---------------------

//-------------ft_atoi.c--------------------
int		    is_positivo(char *str);
int         is_numero(char *letra);
int         times(int n);
void	    ajuste_pontero(char **str);
int         ft_atoi(char *str);
//-------------ft_atoi.c--------------------

# include "ft_str.c"
# include "bsq_map_read.c"
# include "bsq_matrix.c"
# include "bsq_pd.c"
# include "ft_atoi.c"

#endif