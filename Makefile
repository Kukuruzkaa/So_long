# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 12:55:59 by ddiakova          #+#    #+#              #
#    Updated: 2021/05/23 12:56:04 by ddiakova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT 			= Libft/libft.a

OS = $(shell uname -s)

ifeq ($(OS), Linux)
MINILIBX        = minilibx-linux
LIBS 			= -LLibft -L${MINILIBX} -lft -lmlx -lX11 -lXext -lm -lbsd

else 
ifeq ($(OS), Darwin)
MINILIBX        = minilibx-macos
LIBS 			= -LLibft -L${MINILIBX} -lmlx -framework OpenGL -framework AppKit
endif
endif

SRCS 			= so_long.c \
				so_long_utils.c \
				main.c \
				map_checker.c \
				map_parsing.c \
				game_coordinates.c \
				moves.c \
				
OBJS			= $(SRCS:%.c=%.o)

RM 				= rm -rf

CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra -g -c 
#FSAN			= -g3 -fsanitize=address
SRCDIR 			= src
OBJDIR 			= objs

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

all:			$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${FSAN} -I./inc -c $< -o $@

$(LIBFT):
				@make bonus -C Libft

$(NAME):		$(OBJS) $(LIBFT)
				make -C ${MINILIBX}
				$(CC) ${FSAN} -o $(NAME) $(OBJS) $(LIBS) Libft/libft.a

clean:
				$(RM) $(OBJDIR)
				make clean -C Libft
				make -C ${MINILIBX} clean
				
fclean:			clean
				$(RM) $(NAME)
				make fclean -C Libft
				make -C ${MINILIBX} clean

re: 			fclean all

.PHONY: 		all clean fclean re bonus
