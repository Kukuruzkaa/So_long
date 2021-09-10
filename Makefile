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
# MINILIBX        = minilibx-linux
# LIBS 			= -LLibft -L${MINILIBX} -lft -lmlx -lX11 -lXext -lm -lbsd

SRCS 			= so_long.c \
				so_long_utils.c \
				main.c \
				map_checker.c \
				map_parsing.c \
				#minilibx.c \

OBJS			= $(SRCS:%.c=%.o)

RM 				= rm -rf

CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra -g -c 
FSAN			= -g3 -fsanitize=address
SRCDIR 			= src
OBJDIR 			= objs

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

all:			$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

$(LIBFT):
				@make bonus -C Libft

$(NAME):		$(OBJS) $(LIBFT)
				# make -C ${MINILIBX}
				$(CC) -o $(NAME) $(OBJS) Libft/libft.a

clean:
				$(RM) $(OBJDIR)
				make clean -C Libft
				# make -C ${MINILIBX} clean
				
fclean:			clean
				$(RM) $(NAME)
				make fclean -C Libft
				# make -C ${MINILIBX} clean

re: 			fclean all

.PHONY: 		all clean fclean re bonus
