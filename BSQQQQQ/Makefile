# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:01:47 by yugao             #+#    #+#              #
#    Updated: 2023/11/23 22:25:09 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 
CFILE = ./srcs/bsq_map_read.c ./srcs/bsq_matrix.c ./srcs/bsq_pd.c ./srcs/ft_atoi.c ./srcs/ft_str.c ./srcs/main.c
OFILE = ./srcs/bsq_map_read.o ./srcs/bsq_matrix.o ./srcs/bsq_pd.o ./srcs/ft_atoi.o ./srcs/ft_str.o ./srcs/main.o
HFILE = ./includes/
FLAG = -Wall -Wextra -Werror
NAME = bsq

all : $(NAME)
$(NAME) : $(OFILE)
	gcc $(OFILE) -o $@ 
%.o : %.c
	cc -c $(FLAG) $< -I $(HFILE) -o $@


fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY : clean run
clean :
	rm -rf $(OFILE)

MAPS = $(wildcard ./map/*)

run : $(NAME)
	$(foreach map, $(MAPS), ./$(NAME) $(map);)

