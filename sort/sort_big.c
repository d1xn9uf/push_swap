/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:04:52 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:16:22 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	srotate_both(t_node *node, int ra, int rb);
static void	srotate_solo(t_node *node, int r, char x);

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	get_lis(stack_a);
	push_non_lis(stack_a, stack_b);
	push_back(stack_a, stack_b);
}

void	smart_rot(t_stack *stack_a, t_stack *stack_b, int i, int hi)
{
	int	rot[2];

	if (i < stack_b->size - i)
		rot[1] = i;
	else
		rot[1] = i - stack_b->size;
	if (hi < stack_a->size - hi)
		rot[0] = hi;
	else
		rot[0] = hi - stack_a->size;
	srotate_both(get_node(stack_b, i), rot[0], rot[1]);
}

static void	srotate_both(t_node *node, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		node->moves[7] += 1;
		ra -= 1;
		rb -= 1;
	}
	while (ra < 0 && rb < 0)
	{
		node->moves[10] += 1;
		ra += 1;
		rb += 1;
	}
	srotate_solo(node, ra, 'a');
	srotate_solo(node, rb, 'b');
}

static void	srotate_solo(t_node *node, int r, char x)
{
	while (r > 0)
	{
		if (x == 'a')
			node->moves[5] += 1;
		else if (x == 'b')
			node->moves[6] += 1;
		r -= 1;
	}
	while (r < 0)
	{
		if (x == 'a')
			node->moves[8] += 1;
		else if (x == 'b')
			node->moves[9] += 1;
		r += 1;
	}
}
