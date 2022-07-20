/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:08:04 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/09 17:07:49 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(char const *s, char c)
{
	int	i;
	int	identifier;
	int	count;

	identifier = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && identifier == 0)
		{
			identifier = 1;
			count++;
		}
		else if (s[i] == c)
			identifier = 0;
		i++;
	}
	return (count);
}

int	ft_wordlen(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] != c && s[start])
	{
		start++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**arr;

	i = 0;
	k = -1;
	if (!s)
		return (NULL);
	count = word_counter(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (++k < count)
	{
		while (s[i] == c)
			i++;
		j = ft_wordlen(s, c, i);
		arr[k] = ft_substr(s, i, j);
		i += j;
	}
	arr[k] = 0;
	return (arr);
}
