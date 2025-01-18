# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzary <mzary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 21:10:04 by mzary             #+#    #+#              #
#    Updated: 2025/01/15 08:59:06 by mzary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =     push_swap
CHECKER =  checker
CC =       cc -Wall -Wextra -Werror

UTILS =  utils/ft_strlen.c \
		 utils/ft_strncmp.c \
		 utils/ft_strlcpy.c \
		 utils/ft_atoi.c \
		 utils/ft_itoa.c \
		 utils/ft_split.c
FORMAT = format/format.c \
		 format/format_utils.c \
		 format/format_checks.c \
		 format/move_swap.c \
		 format/move_push.c \
		 format/move_rotate.c \
		 format/move_rrotate.c
SORT =   sort/sort.c \
		 sort/sort_three.c \
		 sort/sort_five.c \
		 sort/sort_big.c \
	     sort/get_lis.c \
		 sort/push_non_lis.c \
		 sort/push_back.c \
		 sort/get_moves.c
CHECK =  check/check_bonus.c \
		 check/check_utils_bonus.c \
		 check/gnl.c \
		 check/gnl_utils.c 

SRC =    push_swap.c $(UTILS) $(FORMAT) $(SORT)
OBJ =	 $(SRC:.c=.o)

B_SRC =  $(CHECK) $(UTILS) $(FORMAT)
B_OBJ =  $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

bonus: $(CHECKER)

$(CHECKER): $(B_OBJ)
	$(CC) $^ -o $@


push_swap.o: push_swap.c
	$(CC) -c $< -o $@

utils/%.o: utils/%.c utils/utils.h
	$(CC) -c $< -o $@

format/%.o: format/%.c format/format.h
	$(CC) -c $< -o $@

sort/%.o: sort/%.c sort/sort.h
	$(CC) -c $< -o $@

check/%.o: check/%.c check/check_bonus.h
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: clean