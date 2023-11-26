/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:50:51 by yugao             #+#    #+#             */
/*   Updated: 2023/11/24 22:33:35 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <string.h>

unsigned int hash_function(const char *str) {  //la funcion con que podemos calcular el valor de itendidad de una cadena
    unsigned long hash = 0;                    // se puede considerar como se puede calcular la DNI de una cadena
    int c;

    while ((c = *str++))
        hash = hash * 37 + c;

    return hash % HASH_SIZE;
}

void hash_establecion (hashset *hash, char *dict) //inicio del arry de HASH, hacemos todos los elementos en Hash ser igual que NULL para evitar error
{
    int index;
    char **final = file_to_str (dict); // esta funcion puede separar el contenido del diccionario y implimirlo de forma que 
                                            // en todas las lineas pares salen KEYS, en las inpares salen VALUES
    index = 0;
    while (index < HASH_SIZE)
    {
        hash->bucket[index] = NULL;
        index ++;
    }
    index = 0;
    while (final[index] != 0)
    {
        hash_append_node (hash, final[index], final[index + 1]); //ponemos KEY y VALUES en Hashmap. 
        index += 2;
    }
}

int hash_append_node (hashset *hash, char *key, char *contenido) //es la funcion mencionada arriba
{
    int index = hash_function (key);
    node *present;
    node *new;

    new = (node *) malloc (sizeof(node));
    if (!new)
        return (FALSE);
    new->next = NULL;
    new->key = key;
    new->contenido = contenido;

    if (hash->bucket[index] == NULL)
        hash->bucket[index] = new;
    else
    {
        present = hash->bucket[index];
        while (present->next!= NULL)
            present = present->next;
        present->next = new;
    }
    return (TRUE);
}

char    *hash_query (hashset *hash, char *key) // con esta funcion podemos buscar el VALUE segun el KEY
{                                
    int     index = hash_function (key);        // pasamos el KEY al funcion de HASH para obtener su 'DNI';
    node    *presente;                           

    presente = hash->bucket[index];    
    if (presente && presente->next == NULL)        //si ary[DNI] cuyo next dirige a NULL, signifiga que solo existe este unico elemento, lo devolvemos
        return (presente->contenido);
    else
    {
        while (presente)                            //si ary[DNI] cuyo next no dirige a NULL, significa que en la misma posicion no solo guarda un valor
        {
            if (ft_strcmp (key, presente->key) == 0)    // en este caso hace falta usar un bucle para pasar por este arry con el pontero principio que es                                              // justamente presente. la manera de suma para contador es `presente = presete->next`
                return (presente->contenido);
            presente = presente->next;
        }
        return (NULL);
    }
}

char    **file_to_str (char *dir)
{
    int idendif = open (dir, O_RDONLY);
    char buff;
    char *num;
    unsigned int count;

    count = 0;
    if (!idendif)
        return (NULL);
    while ((read(idendif, &buff, 1)))
        count ++;
    close (idendif);
    num = (char *) malloc (sizeof (char) * count);
    idendif = open (dir, O_RDONLY);
    count = 0;
    while ((read(idendif, &buff, 1)))
        num[count++] = buff;
    close (idendif);
    count = 0;
    char **final = ft_split (num);
    free (num);
    return (final);
}

void hash_display (hashset* hashset) // esta funcion la usamos solamente para hacer prueba y ver los elementos guardados en Hashmap
{
    node    *temp;
    int     index;
    int     j;

    index = 0;
    while (index < HASH_SIZE)
    {
        if (hashset->bucket[index])
        {
            temp = hashset->bucket[index];
            while (temp)
            {
                printf ("KEY:%s  VALUE:%s\n\n", temp->key, temp->contenido);
                temp = temp->next;
            }
        }
        index ++;
    }
}

void hash_distory (hashset *hashset) // la funcion con la que podemos liberar el espacio que hemos solicitado a la memoria
{
    
}

void    ft_putstr (char *str) // alternativa de `printf`
{
    while (*str)
    {
        write (1, str, 1);
        str ++;
    }
}


int main() // 这里我们要用自己的strcat函数   还有自己的strlen函数
{
    
    hashset hash;
    hash_establecion (&hash, "numbers.dict");
    

    char *tem_num;
    char *tem_value;
    char *gewei;
    for (int i = 2; i <= 9; i ++)
    {
        for (int j = 1; j <= 9; j ++)
        {
            tem_num = (char *) malloc (sizeof (char) * 3);
            gewei = (char *) malloc (sizeof (char) * 3);
            tem_num[0] = i + '0';
            tem_num[1] = '0';
            tem_num[2] = '\0';
            gewei[0] = j + '0';
            gewei[1] = '\0';
            tem_value = (char *) malloc (sizeof (char) * (strlen(hash_query(&hash, tem_num)) + strlen (hash_query(&hash, gewei) + 2)));
            strcat(tem_value, hash_query(&hash, tem_num));
            strcat(tem_value, "-");
            strcat(tem_value, hash_query(&hash, gewei));
            tem_num[1] = gewei[0];
            //printf("%s ", tem_num);
            hash_append_node (&hash, tem_num, tem_value);
        }
    }
    //hash_display (&hash);
    ft_putstr(hash_query (&hash, "39"));

}
