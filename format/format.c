/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:14:57 by mzary             #+#    #+#             */
/*   Updated: 2025/01/06 22:58:26 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	format(int ac, char **av, t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	**linker;

	i = 1;
	while (i < ac)
	{
		check_arg(av[i], stack);
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		node->value = ft_atoi(av[i]);
		if (!stack->head)
			stack->head = node;
		else
			*linker = node;
		linker = &node->next;
		stack->size += 1;
		i += 1;
	}
	*linker = stack->head;
	check_duplicate(stack);
}
