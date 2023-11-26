#ifndef RUSH_H

# define RUSH_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define HASH_SIZE 100

typedef struct node // 哈希函数的初始节点
{
    char        *key;
    char        *contenido;
    struct node *next;
} node;

typedef struct hashset //哈希函数的桶节点
{
    node *bucket[HASH_SIZE];
}hashset;

char	*str_cpy(char *str, int head, int tail);
int		cot_len(char *str);
int		ft_strcmp(char *s1, char *s2);

unsigned int hash_function(const char *str);
void hash_establecion (hashset *hash, char *dict);
int hash_append_node (hashset *hash, char *key, char *contenido);
char    *hash_query (hashset *hash, char *key);
char    **file_to_str (char *dir);
void hash_display (hashset* hashset);
void    ft_putstr (char *str);

#endif





char	**ft_split(char *str)
{
	int		index;
	int		largo;
	int		head;
	char	**final;

	index = 0;
	largo = 0;
	final = (char **) malloc (sizeof (char *) * (cot_len (str) + 1));
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			head = index;
			while (str[index] >= '0' && str[index] <= '9')
				index ++;
			final[largo++] = str_cpy (str, head, index);
			while (str[index] == ' ' || str[index] == ':')
				index ++;
			head = index;
			while (str[index] != '\n' && str[index] != '\0')
				index ++;
			final[largo++] = str_cpy (str, head, index);
			index++;
		}
	}
	final[largo] = NULL;
	return (final);
}

int	cot_len(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ':' || str[index] == '\n')
			count ++;
		index ++;
	}
	return (count + 1);
}

char	*str_cpy(char *str, int head, int tail)
{
	char	*final;
	int		index;
	
	index = 0;
	final = (char *) malloc (sizeof (char) * (tail - head + 1));
	while (index < tail - head)
	{
		final[index] = str[index + head];
		index ++;
	}
	final[index] = '\0';
	return (final);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((int)(*s1) - (int)(*s2));
		s1 ++;
		s2 ++;
	}
	return (0);
}