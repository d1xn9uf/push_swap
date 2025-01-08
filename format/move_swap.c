/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:18:04 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:01:44 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

static void	swap(t_stack *stack);

void	swap_a(t_stack *stack_a, int p)
{
	if (stack_a->size > 1)
	{
		swap(stack_a);
		if (p)
			write(STDOUT_FILENO, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack_b, int p)
{
	if (stack_b->size > 1)
	{
		swap(stack_b);
		if (p)
			write(STDOUT_FILENO, "sb\n", 3);
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b, int p)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		swap(stack_a);
		swap(stack_b);
		if (p)
			write(STDOUT_FILENO, "ss\n", 3);
	}
	else
	{
		swap_a(stack_a, p);
		swap_b(stack_b, p);
	}
}

static void	swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;
	t_node	*last_node;

	first_node = stack->head;
	second_node = stack->head->next;
	last_node = get_node(stack, stack->size - 1);
	if (stack->size == 2)
		stack->head = second_node;
	else
	{
		third_node = second_node->next;
		second_node->next = first_node;
		first_node->next = third_node;
		stack->head = second_node;
		last_node->next = second_node;
	}
}
