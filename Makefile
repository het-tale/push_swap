# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 03:23:24 by het-tale          #+#    #+#              #
#    Updated: 2022/06/03 18:57:03 by het-tale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    push_swap

SRCS    =    libft/*.c *.c

OBJCT    =    ${SRCS:.c=.o}

FLAGS    =    -Wall -Wextra -Werror

RM        =    rm -f

CC        =    gcc

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) -g -fsanitize=address

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all

#.PHONY:        all clean fclean re bonus
