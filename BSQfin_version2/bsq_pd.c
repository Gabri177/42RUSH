#include "bsq.h"

position    pd_renova(int columna, int fila, int len)
{
    position p;

    p.x = columna;
    p.y = fila;
    p.len = len;
    return (p);
}

position    pd_matrix(char *c, int x, int y)
{
    int         columna;
    int         fila;
    char        min;
    char        max;
    position    p;

    columna = 1;
    fila = 1;
    max = 1;
    while (fila < y)
    {
        while(columna < x)
        {
            if (c[matrix_index(x, columna, fila)] == '1')
            {
                min = ft_min(c[matrix_index(x, columna - 1, fila)],c[matrix_index(x, columna, fila - 1)],c[matrix_index(x, columna - 1, fila - 1)]);
                c[matrix_index(x, columna, fila)] = min;
                if (max < (int)(c[matrix_index(x, columna, fila)] - '0'))
                {
                    max = min - '0';
                    p = pd_renova (columna, fila, max);
                }
            }
            columna ++;
        }
        columna = 1;
        fila ++;
    }
    return (p);
}

position    pd_p_upperleft (position lower_right) //根据右下角的顶点坐标计算出左上角的顶点坐标, 并进行返回
{
    position ur;

    ur.x = lower_right.x - lower_right.len + 1;
    ur.y = lower_right.y - lower_right.len + 1;
    ur.len = lower_right.len;
    return (ur);
}