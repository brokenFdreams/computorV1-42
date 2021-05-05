# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <fsinged@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 16:49:48 by fsinged           #+#    #+#              #
#    Updated: 2021/02/27 16:49:50 by fsinged          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

FLAGS = -Wall -Wextra -Werror
# src
SRCS = arguments.c computorv1.c discriminant.c ft_sqrtf.c ft_error.c functions.c \
	resolution.c
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
HEADER = -I ./incl/

# libft
LIBDIR = ./libft/
LIB = $(addprefix $(LIBDIR), libft.a)
LIB_INC = -I $(LIBDIR)

# dirs
OBJDIR = ./OBJ/
SRCDIR = ./src/


all:fclean obj $(LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) $(LIB_INC) $(HEADER) -o $@ -c $<

$(LIB):
	@make -C $(LIBDIR)

$(NAME):$(OBJS)
	@gcc $(OBJS) $(LIB) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make fclean -C $(LIBDIR)
	@make clean -C $(MLX)

fclean:clean
	@rm -f $(NAME)

re:fclean all