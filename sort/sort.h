/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:10:12 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:13:57 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../format/format.h"

/* sort.c */
void	sort(t_stack *stack_a, t_stack *stack_b);
void	adjust(t_stack *stack_a);

/* sort_three.c */
void	sort_three(t_stack *stack_a);

/* sort_five.c */
void	sort_five(t_stack *stack_a, t_stack *stack_b);

/* sort_big.c */
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	smart_rot(t_stack *stack_a, t_stack *stack_b, int i, int hi);

/* get_lis.c */
void	get_lis(t_stack *stack_a);

/* push_non_lis.c */
void	push_non_lis(t_stack *stack_a, t_stack *stack_b);

/* push_back.c */
void	push_back(t_stack *stack_a, t_stack *stack_b);

/* get_moves.c */
void	get_moves(t_stack *stack_a, t_stack *stack_b);
int		get_min_rank(t_stack *stack_a);
int		get_max_rank(t_stack *stack_a);

#endif