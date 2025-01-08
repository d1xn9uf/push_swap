/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:43:47 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:12:30 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->head = NULL;
	stack_b->size = 0;
	fill_ranks(stack_a);
	if (stack_a->size <= 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
	adjust(stack_a);
}

void	adjust(t_stack *stack_a)
{
	int		i;
	int		r;

	i = rank_index(stack_a, 0);
	if (i < stack_a->size - i)
		r = i;
	else
		r = i - stack_a->size;
	while (r > 0)
	{
		rotate_a(stack_a, 1);
		r -= 1;
	}
	while (r < 0)
	{
		rrotate_a(stack_a, 1);
		r += 1;
	}
}
