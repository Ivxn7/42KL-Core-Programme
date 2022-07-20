/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:34:25 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/20 16:34:42 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int hexa)
{
	int	len;

	len = 0;
	while (hexa != 0)
	{
		len++;
		hexa /= 16;
	}
	return (len);
}

int	ft_puthexa(unsigned int hexa, char *str)
{
	unsigned int	i;

	i = hexa;
	if (hexa == 0)
		return (write(1, "0", 1));
	else if (i >= 16)
	{
		ft_puthexa((i / 16), str);
		ft_puthexa((i % 16), str);
	}
	else if (i < 16)
		write(1, &str[i], 1);
	return (ft_hexa_len(hexa));
}
