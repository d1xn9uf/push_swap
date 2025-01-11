/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:10:06 by mzary             #+#    #+#             */
/*   Updated: 2025/01/11 21:58:06 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort/sort.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		exit(EXIT_FAILURE);
	stack_a.head = NULL;
	stack_a.size = 0;
	stack_a.lis = NULL;
	if (ac == 2)
		format_one(av[1], &stack_a);
	else
		format(ac, av, &stack_a, 0);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	exit(EXIT_SUCCESS);
}
