#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *temp;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}