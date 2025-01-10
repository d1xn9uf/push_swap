/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 07:32:18 by mzary             #+#    #+#             */
/*   Updated: 2025/01/10 09:29:54 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static void	exec_moves(t_stack *stack_a, t_stack *stack_b, t_move *head);
static void	exec_move(t_stack *stack_a, t_stack *stack_b, char *move);
static int	is_valid(char *move);

t_move	*read_moves(t_stack *stack_a, t_stack *stack_b)
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
			move->next = (t_move *)malloc(sizeof(t_move));
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
		exit_KO();
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
				exit_KO();
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
		if (!is_valid(head->inst))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			free_moves(head);
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
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

static int	is_valid(char *move)
{
	if (!ft_strncmp(move, "sa\n", 3) || !ft_strncmp(move, "sb\n", 3))
		return (1);
	if (!ft_strncmp(move, "pa\n", 3) || !ft_strncmp(move, "pb\n", 3))
		return (1);
	if (!ft_strncmp(move, "ra\n", 3) || !ft_strncmp(move, "rb\n", 3))
		return (1);
	if (!ft_strncmp(move, "rra\n", 4) || !ft_strncmp(move, "rrb\n", 4))
		return (1);
	if (!ft_strncmp(move, "ss\n", 3))
		return (1);
	if (!ft_strncmp(move, "rr\n", 3))
		return (1);
	if (!ft_strncmp(move, "rrr\n", 4))
		return (1);
	return (0);
}
