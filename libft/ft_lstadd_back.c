#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *head;

	head = *lst;
	if (!lst)
		return ;
	if (*lst != NULL)
	{
		head = ft_lstlast(*lst);
		head->next = new;
	}
	else
		*lst = new;
}