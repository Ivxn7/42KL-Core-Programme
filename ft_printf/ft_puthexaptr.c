/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:35:00 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/20 16:35:24 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_ptr(uintptr_t hexa)
{
	uintptr_t	len;

	len = 0;
	while (hexa != 0)
	{
		len++;
		hexa /= 16;
	}
	return (len);
}

void	ft_puthexaptr(uintptr_t hexa, char *str)
{
	if (hexa >= 16)
	{
		ft_puthexaptr(hexa / 16, str);
		ft_puthexaptr(hexa % 16, str);
	}
	else if (hexa <= 16)
		write(1, &str[hexa], 1);
}

int	ft_returnptr(uintptr_t ptr, char *str)
{
	uintptr_t	output;

	output = 0;
	if (ptr == 0)
		return (write(1, "0x0", 3));
	output = write(1, "0x", 2) + ft_hexa_ptr(ptr);
	ft_puthexaptr(ptr, str);
	return (output);
}
