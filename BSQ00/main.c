/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:47 by yugao             #+#    #+#             */
/*   Updated: 2023/11/27 23:50:23 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <string.h>



int	main(void)
{
	char *str_ori;
	char *str_mtrx_ori;
	char *str01;
	size tamano; //数组的大小不是从 0 开始的 而是日常的行列都是从 1 开始计数的
	position p;

	str_ori = map_read ("map2.txt"); // 带有换行的文件内容
	str_mtrx_ori = map_to_oneline (str_ori); // 没有换行的文件内容
	str01 = map_to_matrix(str_ori); // 没有换行的文件内容 而且o变为0 .变为1;
	//ft_putstr(str01);
	tamano = map_size (str_ori, str01); //需要用原来数组, 因为有换行符. 需要用去掉换行符的版本来计算长度;
	//printf ("\n%c\n", str01[matrix_index (tamano.x, tamano.y, 9, 8)]); // 9,8 是10 * 9 数组的最后一个值 这个函数和正常数组逻辑相同 从0开始计数
	p = pd_matrix (str01, tamano.x, tamano.y); // 用动态规划算法进行转换 同时返回左下角的顶点
	//printf ("\n%c\n", ft_min ('0','3','3')); // 最小值测试 
	p = pd_p_upperleft(p); //通过右下角坐标计算左上角坐标
	printf ("Best Solucion : X: %d Y: %d  TAMAÑO:%d x %d \n", p.x, p.y, p.len, p.len);
	matrix_dibujar (p, tamano, str_mtrx_ori); //把原来没有换行的文件内容填充上生成的最大正方形
	matrix_output (tamano.x, str_mtrx_ori); //把没有换行的文件内容按照矩阵进行换行输出
	return 0;
}