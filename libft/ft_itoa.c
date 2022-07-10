/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:08:24 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/09 17:26:36 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	digit_counter(int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long int	num;

	num = n;
	i = digit_counter(n);
	if (n < 0)
	{
		num *= -1;
		i++;
	}
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (i--)
	{
		str[i] = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
