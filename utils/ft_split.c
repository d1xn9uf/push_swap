/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:20:35 by mzary             #+#    #+#             */
/*   Updated: 2025/01/11 21:54:18 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	s_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	free_all(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

static int	ft_splits(char const *s, char c, char **splits, int count)
{
	int	i;
	int	st;
	int	split;

	i = 0;
	split = 1;
	while (split <= count)
	{
		while (s[i] && s[i] == c)
			i++;
		st = i;
		while (s[i] && s[i] != c)
			i++;
		splits[split] = (char *)malloc(sizeof(char) * (i - st + 1));
		if (splits[split] == NULL)
		{
			free_all(splits);
			return (0);
		}
		ft_strlcpy(splits[split], s + st, i - st + 1);
		split++;
	}
	splits[count + 1] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	int		count;

	if (!s)
		return (NULL);
	count = s_count(s, c);
	splits = (char **)malloc(sizeof(char *) * (count + 2));
	if (splits == NULL)
		return (NULL);
	splits[0] = (char *)malloc(sizeof(char));
	if (!splits[0])
	{
		free(splits);
		return (NULL);
	}
	splits[0][0] = '\0';
	if (!ft_splits(s, c, splits, count))
		return (NULL);
	return (splits);
}
