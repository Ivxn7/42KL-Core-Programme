/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:33:05 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/20 16:34:06 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	check_format(va_list ap, const char type)
{
	int		ret;
	char	*uhexa;
	char	*lhexa;

	ret = 0;
	uhexa = "0123456789ABCDEF";
	lhexa = "0123456789abcdef";
	if (type == 'c')
		ret += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		ret += ft_returnptr(va_arg(ap, uintptr_t), lhexa);
	else if (type == 'd' || type == 'i')
		ret += ft_putnum(va_arg(ap, int));
	else if (type == 'u')
		ret += ft_putunum(va_arg(ap, unsigned int));
	else if (type == 'x')
		ret += ft_puthexa(va_arg(ap, unsigned int), lhexa);
	else if (type == 'X')
		ret += ft_puthexa(va_arg(ap, unsigned int), uhexa);
	else if (type == '%')
		ret += print_percent();
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		out;

	i = 0;
	out = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[++i])
			out += check_format(ap, str[i++]);
		else
			out += ft_putchar(str[i++]);
	}
	va_end(ap);
	return (out);
}
