# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzary <mzary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 21:10:04 by mzary             #+#    #+#              #
#    Updated: 2025/01/08 08:18:05 by mzary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =     push_swap
CHECKER =  checker
CC =       cc -Wall -Wextra -Werror

UTILS =  utils/ft_strlen.c utils/ft_strncmp.c utils/ft_strlcpy.c \
		 utils/ft_atoi.c utils/ft_itoa.c
FORMAT = format/format.c format/format_utils.c format/format_checks.c \
		 format/move_swap.c format/move_push.c format/move_rotate.c \
		 format/move_rrotate.c
SORT =   sort/sort.c sort/sort_three.c sort/sort_five.c sort/sort_big.c \
	     sort/get_lis.c sort/push_non_lis.c sort/push_back.c sort/get_moves.c
SRC =    push_swap.c $(UTILS) $(FORMAT) $(SORT)
INC =    utils/utils.h format/format.h sort/sort.h

CHECK =  check/check.c check/check_utils.c check/gnl.c check/gnl_utils.c
B_SRC =  $(CHECK) $(UTILS) $(FORMAT)
B_INC =  check/check.h utils/utils.h format/format.h

all: $(NAME)

$(NAME): $(SRC) $(INC)
	@$(CC) $(SRC) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(B_SRC) $(B_INC)
	@$(CC) $(B_SRC) -o $(CHECKER)

clean:

fclean:
	@rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: clean