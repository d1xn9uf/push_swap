/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:19:59 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:15:33 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->head;
	while (stack->size)
	{
		next = node->next;
		free(node);
		node = next;
		stack->size -= 1;
	}
	if (stack->lis)
		free(stack->lis);
}

t_node	*get_node(t_stack *stack, int i)
{
	t_node	*node;

	node = stack->head;
	while (i > 0)
	{
		node = node->next;
		i -= 1;
	}
	return (node);
}

void	fill_ranks(t_stack *stack)
{
	int		i;
	t_node	*node_i;
	int		j;
	t_node	*node_j;
	int		rank;

	i = 0;
	node_i = stack->head;
	while (i < stack->size)
	{
		rank = 0;
		j = 0;
		node_j = stack->head;
		while (j < stack->size)
		{
			if (node_j->value < node_i->value)
				rank += 1;
			j += 1;
			node_j = node_j->next;
		}
		node_i->rank = rank;
		i += 1;
		node_i = node_i->next;
	}
}

int	rank_index(t_stack *stack, int rank)
{
	int		i;
	t_node	*node_i;

	i = 0;
	node_i = stack->head;
	while (i < stack->size)
	{
		if (node_i->rank == rank)
			return (i);
		i += 1;
		node_i = node_i->next;
	}
	return (i);
}
