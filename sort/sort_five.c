/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:04:54 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:07:27 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	get_pos(t_stack *stack_a, int rank);
static void	push_head(t_stack *stack_a, t_stack *stack_b);
static void	push_two(t_stack *stack_a, t_stack *stack_b);

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		push_b(stack_a, stack_b, 1);
	sort_three(stack_a);
	if (stack_b->size == 1)
		push_head(stack_a, stack_b);
	else
		push_two(stack_a, stack_b);
}

static int	get_pos(t_stack *stack_a, int rank)
{
	int		pos;
	int		h_rank;
	int		i;
	t_node	*node_i;

	if (rank < get_min_rank(stack_a) || rank > get_max_rank(stack_a))
		return (rank_index(stack_a, get_min_rank(stack_a)));
	i = 0;
	node_i = stack_a->head;
	pos = rank_index(stack_a, get_max_rank(stack_a));
	h_rank = get_max_rank(stack_a);
	while (i < stack_a->size)
	{
		if (node_i->rank > rank && node_i->rank < h_rank)
		{
			h_rank = node_i->rank;
			pos = i;
		}
		i += 1;
		node_i = node_i->next;
	}
	return (pos);
}

static void	push_head(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	pos = get_pos(stack_a, stack_b->head->rank);
	if (pos < stack_a->size - pos)
	{
		while (pos-- > 0)
			rotate_a(stack_a, 1);
	}
	else
	{
		pos = stack_a->size - pos;
		while (pos-- > 0)
			rrotate_a(stack_a, 1);
	}
	push_a(stack_a, stack_b, 1);
}

static void	push_two(t_stack *stack_a, t_stack *stack_b)
{
	int	pos[2];

	pos[0] = get_pos(stack_a, stack_b->head->rank);
	pos[1] = get_pos(stack_a, stack_b->head->next->rank);
	if (pos[0] > stack_a->size - pos[0])
		pos[0] = stack_a->size - pos[0];
	if (pos[1] > stack_a->size - pos[1])
		pos[1] = stack_a->size - pos[1];
	pos[1] += 1;
	if (pos[0] <= pos[1])
	{
		push_head(stack_a, stack_b);
		push_head(stack_a, stack_b);
	}
	else
	{
		rotate_b(stack_b, 1);
		push_head(stack_a, stack_b);
		push_head(stack_a, stack_b);
	}
}
