# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:37:50 by tle-monn          #+#    #+#              #
#    Updated: 2024/02/26 14:10:18 by tle-monn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1
CFLAGS 		+= -Wall -Wextra -Werror
CLINKS		=

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= push_swap.c stack_init.c stack_utils.c handle_errors.c init_a_to_b.c init_b_to_a.c push.c rotate.c rev_rotate.c sort_three.c swap.c sort_stacks.c

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus:

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(CLINKS)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)

$(FT):
	$(CLONE) https://github.com/kodokaii/libft_full.git $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if [ -d "$(FT)" ]; then $(MAKE) clean -C $(FT); fi
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(FT)

re: fclean all

.PHONY:		all bonus clear clean fclean re
