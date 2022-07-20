/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:35:59 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/20 16:36:43 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ulen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int num)
{
	unsigned int	len;
	char			*output;

	len = ft_get_ulen(num);
	if (num == 0)
		return (ft_strdup("0"));
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	output[len] = '\0';
	while (num != 0)
	{
		output[len--] = (num % 10) + 48;
		num /= 10;
	}
	return (output);
}

int	ft_putunum(unsigned int num)
{
	char	*n;
	int		i;

	i = 0;
	if (num == 0)
	{
		ft_putchar('0');
		i = 1;
	}
	else
	{
		n = ft_uitoa(num);
		i = ft_putstr(n);
		free (n);
	}
	return (i);
}
