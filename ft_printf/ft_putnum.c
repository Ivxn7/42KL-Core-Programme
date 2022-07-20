/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:35:42 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/20 16:35:43 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putnum(int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		return (write(1, "-", 1) + ft_putnum(n * -1));
	}
	if (n >= 10)
		ft_putnum(n / 10);
	ft_putchar((n % 10) + 48);
	return (ft_get_len(n));
}
