# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahri <itahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:46:56 by itahri            #+#    #+#              #
#    Updated: 2024/06/13 19:49:50 by itahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = $(addprefix srcs/,  main.c args_env_management.c queue_funcs.c exec_management.c execution_funcs.c utils.c pipex.c)

INCLUDES = ./includes -I ./libft/includes/

LIBFT = libft.a
LIB_DIR = ./libft
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = pipex

all : $(LIBFT) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c  $< -o $@ 

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES)  $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft 

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
