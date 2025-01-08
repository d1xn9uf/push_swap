/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:14:37 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 04:36:02 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	host_index(t_stack *stack_a, int rank);
static void	get_cost(t_node *node, int calculated);

void	get_moves(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_node	*node_i;

	i = 0;
	node_i = stack_b->head;
	while (i < stack_b->size)
	{
		get_cost(node_i, 0);
		smart_rot(stack_a, stack_b, i, host_index(stack_a, node_i->rank));
		node_i->moves[3] = 1;
		get_cost(node_i, 1);
		i += 1;
		node_i = node_i->next;
	}
}

static int	host_index(t_stack *stack_a, int rank)
{
	int		hi;
	int		h_rank;
	int		i;
	t_node	*node_i;

	if (rank < get_min_rank(stack_a) || rank > get_max_rank(stack_a))
		return (rank_index(stack_a, get_min_rank(stack_a)));
	i = 0;
	node_i = stack_a->head;
	hi = rank_index(stack_a, get_max_rank(stack_a));
	h_rank = get_max_rank(stack_a);
	while (i < stack_a->size)
	{
		if (node_i->rank > rank && node_i->rank < h_rank)
		{
			h_rank = node_i->rank;
			hi = i;
		}
		i += 1;
		node_i = node_i->next;
	}
	return (hi);
}

int	get_min_rank(t_stack *stack_a)
{
	int		minr;
	int		i;
	t_node	*node_i;

	i = 0;
	node_i = stack_a->head;
	minr = node_i->rank;
	while (i < stack_a->size)
	{
		if (node_i->rank < minr)
			minr = node_i->rank;
		i += 1;
		node_i = node_i->next;
	}
	return (minr);
}

int	get_max_rank(t_stack *stack_a)
{
	int		maxr;
	int		i;
	t_node	*node_i;

	i = 0;
	node_i = stack_a->head;
	maxr = node_i->rank;
	while (i < stack_a->size)
	{
		if (node_i->rank > maxr)
			maxr = node_i->rank;
		i += 1;
		node_i = node_i->next;
	}
	return (maxr);
}

static void	get_cost(t_node *node, int calculated)
{
	int	i;

	node->cost = 0;
	i = 0;
	while (i < 11)
	{
		if (calculated)
			node->cost += node->moves[i];
		else
			node->moves[i] = 0;
		i += 1;
	}
}
