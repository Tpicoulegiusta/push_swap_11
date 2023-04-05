/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:29:28 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/23 11:37:07 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_counti(char *s, char c)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (s[i] == c)
		i++;
	if (s[0] != c || s[i + 1] == '\0')
		k++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	if (s[0] == c && k > 0)
		k++;
	return (k);
}

char	**ft_countj(char **tabtab, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			tabtab [x] = ft_substr(s, j, i - j);
			x++;
		}
	}
	tabtab [x] = NULL;
	return (tabtab);
}

char	**ft_split(char *s, char c)
{
	char	**tabtab;

	if (!s)
	{
		tabtab = malloc(sizeof(char) * 1);
		if (!tabtab)
			return (0);
		tabtab[0] = 0;
		return (tabtab);
	}
	tabtab = malloc(sizeof(char *) * (ft_counti(s, c) + 1));
	if (!tabtab)
		return (0);
	tabtab = ft_countj(tabtab, s, c);
	return (tabtab);
}

char	*ft_substr(char *s, int start, int end)

{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = start;
	ret = malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < end - start)
		ret[i++] = s[j++];
	ret[i] = '\0';
	return (ret);
}
