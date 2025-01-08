/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:39:45 by mzary             #+#    #+#             */
/*   Updated: 2025/01/08 08:15:51 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*(s + length) != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
