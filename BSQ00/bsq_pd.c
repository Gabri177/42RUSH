#include "bsq.h"

position    pd_matrix (char *c, int x, int y)
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
            if (c[matrix_index(x, y, columna, fila)] == '1')
            {
                min = ft_min(c[matrix_index(x, y, columna - 1, fila)],c[matrix_index(x, y, columna, fila - 1)],c[matrix_index(x, y, columna - 1, fila - 1)]);
                //write (1, &min, 1);
                c[matrix_index(x, y, columna, fila)] = min;
                if (max < (int)(min - '0'))
                {
                    max = min - '0';
                    p.x = columna;
                    p.y = fila;
                    p.len = max;
                }
            }
            columna ++;
        }
        columna = 1;
        fila ++;
    }
    return (p);
}

position    pd_p_upperleft (position lower_right)
{
    position ur;

    ur.x = lower_right.x - lower_right.len + 1;
    ur.y = lower_right.y - lower_right.len + 1;
    ur.len = lower_right.len;
    return (ur);
}