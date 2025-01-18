/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:58:33 by mzary             #+#    #+#             */
/*   Updated: 2025/01/15 08:34:28 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	check_arg(char **av, int i, t_stack *stack, int heap)
{
	char	*checker;
	int		invalid;

	checker = ft_itoa(ft_atoi(av[i]));
	invalid = ft_strncmp(checker, av[i], ft_strlen(av[i]));
	free(checker);
	if (invalid || !ft_strlen(av[i]))
	{
		if (heap)
			free_all(av);
		free_stack(stack);
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	check_duplicate(t_stack *stack, char **av, int heap)
{
	int		i[2];
	t_node	*node[2];

	i[0] = 0;
	node[0] = stack->head;
	while (i[0] < stack->size)
	{
		i[1] = i[0] + 1;
		node[1] = get_node(stack, i[1]);
		while (i[1] < stack->size)
		{
			if (node[0]->value == node[1]->value)
			{
				if (heap)
					free_all(av);
				free_stack(stack);
				write(STDERR_FILENO, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			i[1] += 1;
			node[1] = node[1]->next;
		}
		i[0] += 1;
		node[0] = node[0]->next;
	}
}
