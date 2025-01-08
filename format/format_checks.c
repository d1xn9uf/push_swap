/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:58:33 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 04:39:48 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	check_arg(char *arg, t_stack *stack)
{
	char	*checker;
	int		invalid;

	checker = ft_itoa(ft_atoi(arg));
	invalid = ft_strncmp(checker, arg, ft_strlen(arg));
	free(checker);
	if (invalid || !ft_strlen(arg))
	{
		free_stack(stack);
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	check_duplicate(t_stack *stack)
{
	int		i;
	t_node	*node_i;
	int		j;
	t_node	*node_j;

	i = 0;
	node_i = stack->head;
	while (i < stack->size)
	{
		j = i + 1;
		node_j = get_node(stack, j);
		while (j < stack->size)
		{
			if (node_i->value == node_j->value)
			{
				free_stack(stack);
				write(STDERR_FILENO, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j += 1;
			node_j = node_j->next;
		}
		i += 1;
		node_i = node_i->next;
	}
}
