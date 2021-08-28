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

# LIBFT 			= Libft/libft.a

SRCS 			= minilibx.c \

OBJS			= $(SRCS:%.c=%.o)

$(NAME):		$(OBJS) 
				$(CC) -Lmlx_linux -lminilibx_linux -L/Bureau/so_long/minilibx-linux -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

RM 				= rm -rf

CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra -g -c 
SRCDIR 			= src
OBJDIR 			= objs

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

all:			$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@


clean:
				$(RM) $(OBJDIR)
				make clean -C 
				
fclean:			clean
				$(RM) $(NAME)
				make fclean -C 

re: 			fclean all

.PHONY: 		all clean fclean re bonus
