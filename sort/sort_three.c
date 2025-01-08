/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:04:56 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 07:59:18 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_three(t_stack *stack_a)
{
	int	v[3];

	if (stack_a->size == 2 && stack_a->head->rank == 1)
		swap_a(stack_a, 1);
	else if (stack_a->size == 3)
	{
		v[0] = stack_a->head->value;
		v[1] = get_node(stack_a, 1)->value;
		v[2] = get_node(stack_a, 2)->value;
		if ((v[0] < v[2] && v[2] < v[1]) || (v[1] < v[0] && v[0] < v[2])
			|| (v[2] < v[1] && v[1] < v[0]))
			swap_a(stack_a, 1);
		if ((v[0] < v[2] && v[2] < v[1]) || (v[1] < v[2] && v[2] < v[0]))
			rotate_a(stack_a, 1);
		if ((v[2] < v[0] && v[0] < v[1]) || (v[2] < v[1] && v[1] < v[0]))
			rrotate_a(stack_a, 1);
	}
}
