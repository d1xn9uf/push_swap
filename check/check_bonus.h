/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:10:14 by mzary             #+#    #+#             */
/*   Updated: 2025/01/18 15:28:51 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H

# include "../sort/sort.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buff
{
	char			content[BUFFER_SIZE];
	ssize_t			length;
	char			end;
	struct s_buff	*next;
}				t_buff;

typedef struct s_move
{
	char			*inst;
	struct s_move	*next;
}				t_move;

/* gnl.c */
char	*get_next_line(int fd);

/* gnl_utils.c */
void	link_check_buff(t_buff *p_plus, t_buff *p_buff);
char	*return_line(t_buff *p_plus);
void	free_buff(t_buff *p_plus);

/* check_bonus.c */
void	free_moves(t_move *head);
void	exit_ko(void);
void	exit_err(void);

/* check_utils_bonus.c */
t_move	*read_moves(t_stack *stack_a);
void	check_order(t_stack *stack_a, t_stack *stack_b, t_move *head);

#endif