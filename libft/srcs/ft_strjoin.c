/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:55:37 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/07 19:26:54 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	index;
	char	*str;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (index < i)
	{
		if (index < ft_strlen(s1))
			str[index] = s1[index];
		else
			str[index] = s2[index - ft_strlen(s1)];
		index++;
	}
	str[index] = 0;
	return (str);
}
