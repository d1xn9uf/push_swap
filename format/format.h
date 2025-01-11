/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:10:09 by mzary             #+#    #+#             */
/*   Updated: 2025/01/11 22:01:48 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "../utils/utils.h"

typedef struct s_node
{
	int				value;
	int				rank;
	int				cost;
	/* sa sb ss pa pb ra rb rr rra rrb rrr */
	int				moves[11];
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
	int				*lis;
	int				lis_size;
}				t_stack;

/* format.c */
void	format(int ac, char **av, t_stack *stack, int heap);
void	format_one(char *args, t_stack *stack);

/* format_utils.c */
void	free_stack(t_stack *stack);
t_node	*get_node(t_stack *stack, int i);
void	fill_ranks(t_stack *stack);
int		rank_index(t_stack *stack, int rank);

/* format_checks.c */
void	check_arg(char **av, int i, t_stack *stack, int heap);
void	check_duplicate(t_stack *stack, char **av, int heap);

/* move_swap.c */
void	swap_a(t_stack *stack_a, int p);
void	swap_b(t_stack *stack_b, int p);
void	swap_both(t_stack *stack_a, t_stack *stack_b, int p);

/* move_push.c */
void	push_a(t_stack *stack_a, t_stack *stack_b, int p);
void	push_b(t_stack *stack_a, t_stack *stack_b, int p);

/* move_rotate.c */
void	rotate_a(t_stack *stack_a, int p);
void	rotate_b(t_stack *stack_b, int p);
void	rotate_both(t_stack *stack_a, t_stack *stack_b, int p);

/* move_rrotate.c */
void	rrotate_a(t_stack *stack_a, int p);
void	rrotate_b(t_stack *stack_b, int p);
void	rrotate_both(t_stack *stack_a, t_stack *stack_b, int p);

#endif