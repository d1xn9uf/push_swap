/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:10:06 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:11:55 by mzary            ###   ########.fr       */
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
	format(ac, av, &stack_a);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	exit(EXIT_SUCCESS);
}
