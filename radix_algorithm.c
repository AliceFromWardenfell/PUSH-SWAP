#include "push_swap.h"

int	count_digits(int max_number) //carfull with max_num == 0 or -1 or 1
{
	int	res;

	if (!max_number)
		return (0);
	res = 0;
	while (max_number)
	{
		max_number /= 2;
		res++;
	}
	return (res);
}

// static int	choose_direction(t_stack *a, t_technical *t, int i)
// {
// 	int	amount_of_zeroes_1;
// 	int	amount_of_zeroes_2;
// 	int	j;

// 	amount_of_zeroes_1 = 0;
// 	amount_of_zeroes_2 = 0;
// 	j = -1;
// 	while (++j < t->a_num / 2 + 1)
// 	{
// 		if (!((a->expected_pos >> i)&1))
// 			amount_of_zeroes_1++;
// 		a = a->next;
// 	}
// 	while (a)
// 	{
// 		if (!((a->expected_pos >> i)&1))
// 			amount_of_zeroes_2++;
// 		a = a->next;
// 	}
// 	return (amount_of_zeroes_1 + amount_of_zeroes_2);
// }

// void	restore_order(t_stack **a, t_technical *t, int val)
// {
// 	t_stack *tmp;
// 	int		k;

// 	k = 0;
// 	tmp = *a;
// 	while (tmp && tmp->expected_pos != val)
// 	{
// 		k++;
// 		tmp = tmp->next;
// 	}
// 	while ((*a)->expected_pos != val)
// 	{
// 		if (k > t->a_num / 2 + 1)
// 			r_rotate(a, t, A);
// 		else
// 			rotate(a, t, A);
// 	}
// }

static void	push_or_rotate(t_stack **a, t_stack **b, t_technical *t, int i)
{
	int		j;

	j = -1;
	while (++j < t->a_num + t->b_num)
	{
		if (((*a)->expected_pos >> i)&1)
			rotate(a, t, A);
		else
			push(a, b, t, B);
	}
}

void	radix_algorithm(t_stack **a, t_stack **b, t_technical *t)
{
	int		amount_of_digits;
	int		i;

	amount_of_digits = count_digits(t->a_num);
	i = -1;
	while (++i < amount_of_digits)
	{
		push_or_rotate(a, b, t, i);
		while (*b)
			push(a, b, t, A);
	}
}