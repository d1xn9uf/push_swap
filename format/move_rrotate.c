/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:50:55 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:02:24 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

static void	rrotate(t_stack *stack);

void	rrotate_a(t_stack *stack_a, int p)
{
	if (stack_a->size > 1)
	{
		rrotate(stack_a);
		if (p)
			write(STDOUT_FILENO, "rra\n", 4);
	}
}

void	rrotate_b(t_stack *stack_b, int p)
{
	if (stack_b->size > 1)
	{
		rrotate(stack_b);
		if (p)
			write(STDOUT_FILENO, "rrb\n", 4);
	}
}

void	rrotate_both(t_stack *stack_a, t_stack *stack_b, int p)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		rrotate(stack_a);
		rrotate(stack_b);
		if (p)
			write(STDOUT_FILENO, "rrr\n", 4);
	}
	else
	{
		rrotate_a(stack_a, p);
		rrotate_b(stack_b, p);
	}
}

static void	rrotate(t_stack *stack)
{
	stack->head = get_node(stack, stack->size - 1);
}
