# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 03:23:24 by het-tale          #+#    #+#              #
#    Updated: 2022/06/13 12:16:24 by het-tale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    push_swap
NAME_BONUS    =    checker
BONUS_DIR = bonus
SRCS    =    libft/*.c *.c

SRCB    =    libft/*.c bonus/*.c bonus/gnl/*.c ps*.c sort_big_stack_utils*.c sort_three_five.c

OBJCT    =    ${SRCS:.c=.o}

OBJCTB    =    ${SRCB:.c=.o}

FLAGS    =    -Wall -Wextra -Werror

RM        =    rm -f

CC        =    gcc

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(SRCB)
	$(CC) $(FLAGS) $(SRCB) -o $(NAME_BONUS)
clean :
	${RM} ${OBJCT}
	${RM} ${OBJCTB}

fclean : clean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re : fclean all

#.PHONY:        all clean fclean re bonus
