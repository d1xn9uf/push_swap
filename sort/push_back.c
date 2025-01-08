/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:58:24 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:08:44 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	push_node(t_stack *stack_a, t_stack *stack_b, int mci);

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		cost;
	int		mci;
	int		i;

	while (stack_b->size)
	{
		get_moves(stack_a, stack_b);
		node = stack_b->head;
		cost = node->cost;
		mci = 0;
		i = 0;
		while (i < stack_b->size)
		{
			if (node->cost < cost)
			{
				mci = i;
				cost = node->cost;
			}
			i += 1;
			node = node->next;
		}
		push_node(stack_a, stack_b, mci);
	}
}

static void	push_node(t_stack *stack_a, t_stack *stack_b, int mci)
{
	int	*moves;

	moves = get_node(stack_b, mci)->moves;
	while (moves[7]--)
		rotate_both(stack_a, stack_b, 1);
	while (moves[10]--)
		rrotate_both(stack_a, stack_b, 1);
	while (moves[5]--)
		rotate_a(stack_a, 1);
	while (moves[6]--)
		rotate_b(stack_b, 1);
	while (moves[8]--)
		rrotate_a(stack_a, 1);
	while (moves[9]--)
		rrotate_b(stack_b, 1);
	push_a(stack_a, stack_b, 1);
}
