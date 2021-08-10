#include "push_swap.h"

void	clean(t_stack **a, t_stack **b, t_technical *t)
{
	t_stack	*to_free;
	t_inst	*_to_free;

	if (t->sorted_arr)
		free(t->sorted_arr);
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
	while (t->inst)
	{
		_to_free = t->inst;
		t->inst = t->inst->next;
		free(_to_free);
	}
	while (t->inst_ch)
	{
		_to_free = t->inst_ch;
		t->inst_ch = t->inst_ch->next;
		free(_to_free);
	}
}

int		error(void)
{
	ft_putstr("Error\n");
	return (-1);
}
