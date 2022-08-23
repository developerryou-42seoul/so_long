# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sryou <sryou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 10:33:16 by sryou             #+#    #+#              #
#    Updated: 2022/08/23 14:59:04 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = Libft
LIBFT_LIB = ft
LIBMLX = mlx
LIBMLX_LIB = mlx
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRCS = main.c \
		get_next_line_utils.c \
		get_next_line.c \
		init.c \
		map.c \
		control.c \
		image.c
		
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT)/
	make all -C $(LIBMLX)/
	$(CC) $(CFLAGS) $^ -L./$(LIBFT) -l$(LIBFT_LIB) -L./$(LIBMLX) -l$(LIBMLX_LIB) -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

all : $(NAME)
clean :
	make fclean -C $(LIBFT)/
	make clean -C $(LIBMLX)/
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : 
	make fclean
	make all
