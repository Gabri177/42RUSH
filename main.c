/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:13:47 by yugao             #+#    #+#             */
/*   Updated: 2023/11/28 13:47:27 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int arc, char **arg)
{
	char *str_ori;
	char *str_mtrx_ori;
	char *str01;
	size tamano; //数组的大小不是从 0 开始的 而是日常的行列都是从 1 开始计数的
	position p;
	info_doc info;

	int len;
	int	index;

	index = 1;
	len = arc;
	if (arc == 1)
	{
		ft_putstr ("NO INFORMACION DE MAP !!!\n");
		return (0);
	}
	while (index < arc)
	{
		str_ori = map_read (arg[index]); // 这是对原来文件原封不动的读取, 包括第一行的非地图信息, 包括最后一行的换行所有信息的字符串
		map_dato (&info, str_ori); //通过这个函数把原文件字符串中 列的信息, 地图开始位置, 空白位置,障碍位置,填充位置字符串进行提取
		str_mtrx_ori = map_to_oneline (str_ori + info.ini_posicion); // 我们通过info中记录的地图起始位置传递剩余的字符串
		str01 = map_to_matrix(str_ori + info.ini_posicion, info); // 没有换行的文件内容 而且所有障碍变为0 所有的可填充位置变为1;
		tamano = map_size (str_ori, str01); //需要用(原始的带有换行符的数组)和(去掉第一行后没有换行符的数组来计算列的数量)通过比较可以得出地图是否合规;
		if (tamano.y != info.fila || tamano.y == 0) //当我们读取的列的数量与我们计算的列的数量不一致 ,则地图格式错误.
		{
			ft_putstr ("ERROR FORMAT OF MAP !!!\n");
			index ++;
			continue;
		}
		p = pd_matrix (str01, tamano.x, tamano.y); // 用动态规划算法进行最大值的计算, 记录第一次出现最大值的位置, 并且返回最大值的位置
		p = pd_p_upperleft(p); //通过右下角坐标计算左上角坐标
		matrix_dibujar (p, tamano, str_mtrx_ori, info.llena); //把原来没有换行的文件内容填充上生成的最大正方形
		matrix_output (tamano.x, str_mtrx_ori); //把没有换行的文件内容按照矩阵进行换行输出
		index ++;
		ft_putstr ("\n\n");
	}
	return 0;
}
