/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:12:13 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:15:16 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	get_cis(t_stack *stack_a, int i);
static void	extract_lis(t_stack *stack_a, int lis_i);

void	get_lis(t_stack *stack_a)
{
	int	lis_size;
	int	lis_index;
	int	cis_size;
	int	i;

	lis_size = 1;
	lis_index = 0;
	i = 0;
	while (i < stack_a->size && stack_a->size - i > lis_size)
	{
		cis_size = get_cis(stack_a, i);
		if (cis_size > lis_size)
		{
			lis_size = cis_size;
			lis_index = i;
		}
		i += 1;
	}
	stack_a->lis_size = lis_size;
	extract_lis(stack_a, lis_index);
}

static int	get_cis(t_stack *stack_a, int i)
{
	int		cis;
	t_node	*node;
	int		rank;

	cis = 1;
	node = get_node(stack_a, i);
	rank = node->rank;
	while (i < stack_a->size)
	{
		if (node->rank > rank)
		{
			cis += 1;
			rank = node->rank;
		}
		i += 1;
		node = node->next;
	}
	return (cis);
}

static void	extract_lis(t_stack *stack_a, int lis_i)
{
	t_node	*node;
	int		rank;
	int		i;

	stack_a->lis = (int *)malloc(sizeof(int) * stack_a->lis_size);
	if (!stack_a->lis)
	{
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
	i = 0;
	rank = -1;
	node = get_node(stack_a, lis_i);
	while (i < stack_a->lis_size)
	{
		while (node->rank < rank)
			node = node->next;
		stack_a->lis[i] = node->rank;
		rank = node->rank;
		node = node->next;
		i += 1;
	}
}
