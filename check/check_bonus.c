/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:07:55 by mzary             #+#    #+#             */
/*   Updated: 2025/01/11 21:58:33 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

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
	if (ac == 2)
		format_one(av[1], &stack_a);
	else
		format(ac, av, &stack_a, 0);
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

void	exit_ko(void)
{
	write(STDOUT_FILENO, "KO\n", 3);
	exit(EXIT_FAILURE);
}
