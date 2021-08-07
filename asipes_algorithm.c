#include "push_swap.h"

static int	split_a(t_stack **a, t_stack **b, t_technical *t, int mid)
{
	int		rotations;
	int		k;

	k = (t->a_num + t->b_num) - t->as_alg.wanted_el + 1;
	rotations = 0;
	while (k--)
		if ((*a)->expected_pos > mid)
		{
			rotations++;
			rotate(a, t, A);
		}
		else
			push(a, b, t, B);
	return (rotations);
}

static void	align_a(t_stack **a, t_technical *t, int k)
{
	int		dir;

	if (k > t->as_alg.wanted_el - 1)
	{
		k = t->as_alg.wanted_el - 1;
		dir = UP;
	}
	else
		dir = DOWN;
	while (k--)
		if (dir == UP)
			rotate(a, t, A);
		else if (dir == DOWN)
			r_rotate(a, t, A);
}

static void	push_or_rotate(t_stack **a, t_stack **b, t_technical *t, int mid)
{
	if ((*b)->expected_pos == t->as_alg.wanted_el)
	{
		t->as_alg.wanted_el++;
		(*b)->curr_tag = SORTED;
		push(a, b, t, A);
		rotate(a, t, A);
	}
	else if ((*b)->expected_pos < mid)
		rotate(b, t, B);
	else
	{
		(*b)->curr_tag = t->as_alg.global_tag;
		push(a, b, t, A);
	}
}

static void	split_b(t_stack **a, t_stack **b, t_technical *t, int max)
{
	int		mid;
	int		k;

	while (*b)
	{
		mid = (max - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
		t->as_alg.global_tag++;
		k = t->b_num; //?
		while (k--)
			push_or_rotate(a, b, t, mid);
	}
}

static void	move_tagged(t_stack **a, t_stack **b, t_technical *t, int tag)
{
	while ((*a)->curr_tag == tag)
		push(a, b, t, B);
}

void	asipes_algorithm(t_stack **a, t_stack **b, t_technical *t)
{
	int		max;
	int		mid;
	int 	rotations;

	max = t->a_num;
	while (mid < max)
	{
		mid = (max - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
		rotations = split_a(a, b, t, mid);
		align_a(a, t, rotations);
		split_b(a, b, t, mid);
		while ((*a)->curr_tag != DEFAULT && (*a)->curr_tag != SORTED)
		{
			move_tagged(a, b, t, (*a)->curr_tag);
			split_b(a, b, t, mid);
		}
	}
}