/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:06:43 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/07 14:01:58 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	chara;

	i = 0;
	chara = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char *)str == chara)
		{
			return ((unsigned char *)str);
		}
		i++;
		str++;
	}
	return (NULL);
}
