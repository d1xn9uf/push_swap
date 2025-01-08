/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:45:56 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:03:00 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

static void	rotate(t_stack *stack);

void	rotate_a(t_stack *stack_a, int p)
{
	if (stack_a->size > 1)
	{
		rotate(stack_a);
		if (p)
			write(STDOUT_FILENO, "ra\n", 3);
	}
}

void	rotate_b(t_stack *stack_b, int p)
{
	if (stack_b->size > 1)
	{
		rotate(stack_b);
		if (p)
			write(STDOUT_FILENO, "rb\n", 3);
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b, int p)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		if (p)
			write(STDOUT_FILENO, "rr\n", 3);
	}
	else
	{
		rotate_a(stack_a, p);
		rotate_b(stack_b, p);
	}
}

static void	rotate(t_stack *stack)
{
	stack->head = stack->head->next;
}
