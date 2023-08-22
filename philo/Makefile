# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylr <ylr@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 08:47:51 by ylarhris          #+#    #+#              #
#    Updated: 2023/08/22 10:45:32 by ylr              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./includes/Libft/ft_atoi.c ./includes/Libft/ft_calloc.c ./includes/Libft/ft_isalnum.c \
		./includes/Libft/ft_isdigit.c ./includes/Libft/ft_itoa.c ./includes/Libft/ft_split.c \
		./includes/Libft/ft_strdup.c ./includes/Libft/ft_strjoin.c ./includes/Libft/ft_strlen.c \
		./includes/Libft/ft_substr.c ./includes/Libft/ft_strcmp.c ./includes/Libft/ft_strncmp.c ./includes/Libft/ft_putchar_fd.c \
		./includes/Libft/ft_putstr_fd.c ./includes/Libft/ft_bzero.c \
		./src/philo.c ./src/utils.c ./src/init.c
	
OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m- philo compiled!\033[0m"

clean :
	@rm -rf $(OBJS)
	@echo "\033[1;33m- Object files removed!\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[1;31m- philo deleted!\033[0m"

re : fclean all