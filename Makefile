# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 03:23:24 by het-tale          #+#    #+#              #
#    Updated: 2022/06/13 13:03:00 by het-tale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    push_swap
NAME_BONUS    =    checker
BONUS_DIR = bonus
SRCS    =    libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_substr.c \
			ps_errors.c ps_list.c ps_push_pop.c ps_push.c ps_rev_rotate.c ps_rotate.c ps_stack.c ps_swap_stacks.c push_swap.c\
			sort_100.c sort_big_stack_utils.c sort_big_stack_utils2.c sort_three_five.c

SRCB    =    libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_substr.c \
			bonus/bonus.c bonus/gnl/get_next_line_utils.c bonus/gnl/get_next_line.c \
			ps_errors.c ps_list.c ps_push_pop.c ps_push.c ps_rev_rotate.c ps_rotate.c ps_stack.c ps_swap_stacks.c \
			sort_big_stack_utils.c sort_big_stack_utils2.c sort_three_five.c

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
	${RM} ${OBJCT} ${OBJCTB}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all
