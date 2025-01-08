/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:31:54 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:03:23 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

static void	push(t_stack *src, t_stack *dst);

void	push_a(t_stack *stack_a, t_stack *stack_b, int p)
{
	if (stack_b->size)
	{
		push(stack_b, stack_a);
		if (p)
			write(STDOUT_FILENO, "pa\n", 3);
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b, int p)
{
	if (stack_a->size)
	{
		push(stack_a, stack_b);
		if (p)
			write(STDOUT_FILENO, "pb\n", 3);
	}
}

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*old_dst_head;
	t_node	*new_src_head;

	new_src_head = src->head->next;
	old_dst_head = dst->head;
	dst->head = src->head;
	dst->head->next = old_dst_head;
	dst->size += 1;
	get_node(dst, dst->size - 1)->next = dst->head;
	src->head = new_src_head;
	src->size -= 1;
	if (src->size == 0)
		src->head = NULL;
	else
		get_node(src, src->size - 1)->next = src->head;
}
