# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:38:51 by mangarci          #+#    #+#              #
#    Updated: 2020/01/21 16:38:53 by mangarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PF =	ft_printf.c convert_to_char.c format.c precision.c print_int.c print_percent.c \
print_string.c to_space.c print_final_str.c modify_str.c print_hex.c ft_putnbr_base.c

SRC_LFT = ft_strlen.c ft_substr.c ft_strjoin.c ft_atoi.c ft_itoa.c ft_strdup.c

OBJET_PF = $(SRC_PF:.c=.o)
OBJET_LFT = $(SRC_LFT:.c=.o)
LIBFT_PATH =  ../libft

FLAGS = -Wall -Werror -Wextra

LIB = $(addprefix $(LIBFT_PATH)/, $(OBJET_LFT))
GCC = gcc
AR = ar
ARFLAGS = rc
MAKE = make

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJET_PF) $(SRC_PF) $(LIB)
		@$(MAKE) -C $(LIBFT_PATH)
		@echo Compiling $(NAME)
		@$(GCC) $(FLAGS) -c $(SRC_PF)
		@$(AR) $(ARFLAGS) $(NAME) $(OBJET_PF) $(LIB)
		@ranlib $(NAME)
		@echo ======[Done]======

%.o : %.c
		@echo "$(NAME) >>> Add/Update $^"

clean:
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET_PF)

fclean: clean
		@$(MAKE) -C $(LIBFT_PATH) fclean
		@echo Clean $(NAME)
		@rm -rf $(NAME)
		@echo ======[Clean]======

re: fclean all