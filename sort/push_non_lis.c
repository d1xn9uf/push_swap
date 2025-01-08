/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_non_lis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:58:07 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:13:26 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	not_lis(t_stack *stack_a, t_node *node);

void	push_non_lis(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	int		count;
	t_node	*node;

	pivot = stack_a->size / 2;
	count = stack_a->size - stack_a->lis_size;
	node = stack_a->head;
	while (count)
	{
		if (not_lis(stack_a, node))
		{
			push_b(stack_a, stack_b, 1);
			if (node->rank < pivot)
				rotate_b(stack_b, 1);
			count -= 1;
		}
		else
			rotate_a(stack_a, 1);
		node = stack_a->head;
	}
}

static int	not_lis(t_stack *stack_a, t_node *node)
{
	int	i;

	i = 0;
	while (i < stack_a->lis_size)
	{
		if (node->rank == stack_a->lis[i])
			return (0);
		i += 1;
	}
	return (1);
}
