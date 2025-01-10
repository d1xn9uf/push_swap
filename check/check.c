/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:07:55 by mzary             #+#    #+#             */
/*   Updated: 2025/01/10 09:29:04 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_move	*moves;

	if (ac == 1)
		exit(EXIT_FAILURE);
	stack_a.head = NULL;
	stack_a.size = 0;
	stack_a.lis = NULL;
	format(ac, av, &stack_a);
	stack_b.head = NULL;
	stack_b.size = 0;
	stack_b.lis = NULL;
	moves = read_moves(&stack_a, &stack_b);
	check_order(&stack_a, &stack_b, moves);
	free_stack(&stack_a);
	write(STDOUT_FILENO, "OK\n", 3);
	exit(EXIT_SUCCESS);
}

void	free_moves(t_move *head)
{
	t_move	*next;

	while (head)
	{
		next = head->next;
		if (head->inst)
			free(head->inst);
		free(head);
		head = next;
	}
}

void	exit_KO(void)
{
	write(STDOUT_FILENO, "KO\n", 3);
	exit(EXIT_FAILURE);
}
