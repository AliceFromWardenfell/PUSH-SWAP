#include "push_swap.h"

void	clean(t_stack **a, t_stack **b, t_technical *t)
{
	t_stack	*to_free;
	
	free(t->instructions);
	while (*a)
	{
		to_free = *a;
		*a = (*a)->next;
		free(to_free);
	}
	while (*b)
	{
		to_free = *b;
		*b = (*b)->next;
		free(to_free);
	}
}

int		error(void)
{
	ft_putstr("Error\n");
	return (-1);
}
