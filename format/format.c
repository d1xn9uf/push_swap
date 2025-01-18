/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:14:57 by mzary             #+#    #+#             */
/*   Updated: 2025/01/15 08:34:33 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	format(int ac, char **av, t_stack *stack, int heap)
{
	int		i;
	t_node	*node;
	t_node	**linker;

	i = 1;
	while (i < ac)
	{
		check_arg(av, i, stack, heap);
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
	check_duplicate(stack, av, heap);
}

void	format_one(char *args, t_stack *stack)
{
	int		ac;
	char	**av;

	if (!ft_strlen(args))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	av = ft_split(args, ' ');
	if (!av)
		exit(EXIT_FAILURE);
	ac = 0;
	while (av[ac])
		ac += 1;
	if (ac == 1)
	{
		free_all(av);
		exit(EXIT_FAILURE);
	}
	format(ac, av, stack, 1);
	free_all(av);
}
