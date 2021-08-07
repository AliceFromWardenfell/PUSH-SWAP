#include "push_swap.h"

t_stack	*create_node(int val)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		exit(error());
	if (tmp)
	{
		tmp->val = val;
		tmp->next = NULL;
		tmp->curr_tag = -1;
	}
	return (tmp);
}

void	addnode_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	addnode_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
