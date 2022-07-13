/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:52 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/13 15:43:49 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_max(int value)
{
	if (value == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *c)
{
	int	sign;
	int	i;
	int	num;
	int	counter;

	sign = 1;
	i = 0;
	num = 0;
	counter = 0;
	while (c[i] == ' ' || c[i] == '\t' || c[i] == '\n'
		|| c[i] == '\v' || c[i] == '\r' || c[i] == '\f')
		i++;
	if (c[i] == '-')
		sign *= -1;
	if (c[i] == '+' || c[i] == '-')
		i++;
	while (c[i] >= '0' && c[i] <= '9' && c[i] != '\0')
	{
		if (counter > 10 || num > 2147483647)
			return (check_max(sign));
		num = (num * 10) + (c[i] - 48);
		i++;
		counter++;
	}
	return (num * sign);
}
