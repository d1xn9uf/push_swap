/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:07:55 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 07:53:56 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		exit(EXIT_FAILURE);
	stack_a.head = NULL;
	stack_a.size = 0;
	stack_a.lis = NULL;
	format(ac, av, &stack_a);
	stack_b.head = NULL;
	stack_b.size = 0;
	stack_b.lis = NULL;
	exec_moves(&stack_a, &stack_b);
	check_order(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	write(STDOUT_FILENO, "OK\n", 3);
	exit(EXIT_SUCCESS);
}
