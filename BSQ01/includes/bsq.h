/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:41 by yugao             #+#    #+#             */
/*   Updated: 2023/11/29 14:12:39 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_size
{
	int	x;
	int	y;
}	t_size;

typedef struct t_post
{
	int	x;
	int	y;
	int	len;
}	t_post;

typedef struct t_info
{
	char	*ori;
	char	vacio;
	char	obstaculo;
	char	llena;
	int		fila;
	int		ini_posicion;
}	t_info;

void		ft_putstr(char *str);
int			ft_strlen(char *str);
char		ft_min(char l1, char l2, char l3);
int			ft_isnumero(char c);
int			map_len(char *dir);
char		*map_read(char *dir);
char		*map_to_matrix(char *str, t_info info);
void		map_dato(t_info *info, char *str);
int			matrix_index(int max_x, int x, int y);
void		matrix_output(int max_x, char *str);
void		matrix_dibujar(t_post p, t_size tamano, char *str, char llena);
t_post		pd_matrix(char *c, int x, int y);
int			is_positivo(char *str);
int			is_numero(char *letra);
int			times(int n);
void		ajuste_pontero(char **str);
int			ft_atoi(char *str);
char		*map_to_oneline(char *str);
t_size		map_t_size(char *str, char *str2);
t_post		pd_p_upperleft(t_post lower_right);
t_size		map_t_t_size(char *str, char *str2);

#endif