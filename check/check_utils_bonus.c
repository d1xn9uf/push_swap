/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 07:32:18 by mzary             #+#    #+#             */
/*   Updated: 2025/01/18 15:35:14 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

static void	exec_moves(t_stack *stack_a, t_stack *stack_b, t_move *head);
static void	exec_move(t_stack *stack_a, t_stack *stack_b, char *move);
static int	check_instruction(t_move *move, t_stack *stack_a, t_move *head);

t_move	*read_moves(t_stack *stack_a)
{
	t_move	*head;
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (!move)
	{
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
	head = move;
	while (move)
	{
		move->inst = get_next_line(STDIN_FILENO);
		if (!move->inst)
			move->next = NULL;
		else
		{
			if (check_instruction(move, stack_a, head) == -1)
				exit_err();
			move->next = (t_move *)malloc(sizeof(t_move));
		}
		move = move->next;
	}
	return (head);
}

void	check_order(t_stack *stack_a, t_stack *stack_b, t_move *head)
{
	int	i;
	int	j;

	exec_moves(stack_a, stack_b, head);
	if (stack_b->size)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit_ko();
	}
	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (get_node(stack_a, i)->value > get_node(stack_a, j)->value)
			{
				free_stack(stack_a);
				exit_ko();
			}
			j += 1;
		}
		i += 1;
	}
}

static void	exec_moves(t_stack *stack_a, t_stack *stack_b, t_move *head)
{
	t_move	*move;

	move = head;
	while (move->inst)
	{
		exec_move(stack_a, stack_b, move->inst);
		move = move->next;
	}
	free_moves(head);
}

static void	exec_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		swap_a(stack_a, 0);
	if (!ft_strncmp(move, "sb\n", 3))
		swap_b(stack_b, 0);
	if (!ft_strncmp(move, "ss\n", 3))
		swap_both(stack_a, stack_b, 0);
	if (!ft_strncmp(move, "pa\n", 3))
		push_a(stack_a, stack_b, 0);
	if (!ft_strncmp(move, "pb\n", 3))
		push_b(stack_a, stack_b, 0);
	if (!ft_strncmp(move, "ra\n", 3))
		rotate_a(stack_a, 0);
	if (!ft_strncmp(move, "rb\n", 3))
		rotate_b(stack_b, 0);
	if (!ft_strncmp(move, "rr\n", 3))
		rotate_both(stack_a, stack_b, 0);
	if (!ft_strncmp(move, "rra\n", 4))
		rrotate_a(stack_a, 0);
	if (!ft_strncmp(move, "rrb\n", 4))
		rrotate_b(stack_b, 0);
	if (!ft_strncmp(move, "rrr\n", 4))
		rrotate_both(stack_a, stack_b, 0);
}

static int	check_instruction(t_move *move, t_stack *stack_a, t_move *head)
{
	char	*inst;
	int		len;

	inst = move->inst;
	len = ft_strlen(inst);
	if (!ft_strncmp(inst, "sa\n", len) || !ft_strncmp(inst, "sb\n", len))
		return (0);
	else if (!ft_strncmp(inst, "pa\n", len) || !ft_strncmp(inst, "pb\n", len))
		return (0);
	else if (!ft_strncmp(inst, "ra\n", len) || !ft_strncmp(inst, "rb\n", len))
		return (0);
	else if (!ft_strncmp(inst, "rra\n", len) || !ft_strncmp(inst, "rrb\n", len))
		return (0);
	else if (!ft_strncmp(inst, "ss\n", len) || !ft_strncmp(inst, "rr\n", len))
		return (0);
	else if (!ft_strncmp(inst, "rrr\n", len))
		return (0);
	free_stack(stack_a);
	move->next = NULL;
	free_moves(head);
	return (-1);
}
