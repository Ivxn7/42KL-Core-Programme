/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:20:49 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/13 15:46:54 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rm;

	tmp = *lst;
	while (tmp != NULL)
	{
		rm = tmp;
		tmp = tmp->next;
		(*del)(rm->content);
		free(rm);
	}
	*lst = NULL;
}
