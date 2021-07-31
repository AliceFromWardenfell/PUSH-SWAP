#include "push_swap.h"

void	clean(t_stack **a, t_stack **b, t_technical *t)
{
	free(t->instructions);
	
}

int		error(void)
{
	ft_putstr("Error\n");
	return (-1);
}
