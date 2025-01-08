/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:10:14 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 07:32:10 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

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

/* gnl.c */
char	*get_next_line(int fd);

/* gnl_utils.c */
void	link_check_buff(t_buff *p_plus, t_buff *p_buff);
char	*return_line(t_buff *p_plus);
void	free_buff(t_buff *p_plus);

/* check_utils.c */
void	exec_moves(t_stack *stack_a, t_stack *stack_b);
void	check_order(t_stack *stack_a, t_stack *stack_b);

#endif