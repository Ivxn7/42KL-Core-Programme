/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:32:05 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/13 15:59:38 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	size_t	*ptr;

	total_size = nitems * size;
	ptr = malloc(total_size);
	if (!ptr || size == SIZE_MAX)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
