#include "push_swap.h"

static void split_b(t_stack **a, t_stack **b, t_technical *t, int curr_mid)
{
	if ((*b)->expected_pos == t->as_alg.wanted_el)
	{
		t->as_alg.wanted_el++;
		(*b)->curr_tag = -1;
		push(a, b, t, A);
		rotate(a, t, A);
	}
	else if ((*b)->expected_pos < curr_mid)
		rotate(b, t, B);
	else
	{
		(*b)->curr_tag = t->as_alg.global_tag;
		push(a, b, t, A);
	}
}

static void	sort_b(t_stack **a, t_stack **b, t_technical *t, int curr_mid)
{
	int		i;
	int		k;

	while (*b)
	{
		t->as_alg.global_tag++;
		curr_mid = (curr_mid - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
		i = -1;
		k = t->b_num;
		while (++i < k) // ???
			split_b(a, b, t, curr_mid);
	}
}

static int	find_max(t_stack *tmp)
{
	int		max;

	max = 0;
	while (tmp)
	{
		if (tmp->expected_pos > max)
			max = tmp->expected_pos;
		tmp = tmp->next;
	}
	return (max);
}

static void	push_tagged_back(t_stack **a, t_stack **b, t_technical *t)
{
	int		curr_tag;

	curr_tag = (*a)->curr_tag;
	while (curr_tag && curr_tag != -1)
	{
		curr_tag = (*a)->curr_tag;
		while ((*a)->curr_tag == curr_tag)
			push(a, b, t, B);
		sort_b(a, b, t, find_max(*b));
		curr_tag = (*a)->curr_tag;
	}
}

void	asipes_algorithm(t_stack **a, t_stack **b, t_technical *t)
{
	int		i;
	int		rotations;

	t->as_alg.curr_max = t->a_num;
	t->as_alg.curr_mid = t->a_num / 2 + 1;
	i = -1;
	while (++i < t->a_num + t->b_num) //spin in right direction and don't over spin if all els were moved
		if ((*a)->expected_pos > t->as_alg.curr_mid)
			rotate(a, t, A);
		else
			push(a, b, t, B);
	sort_b(a, b, t, t->as_alg.curr_mid);
	// change mid
	push_tagged_back(a, b, t);
	rotations = 0;
	while (t->as_alg.wanted_el != t->a_num + t->b_num + 1)
	{
		while ((*a)->curr_tag != -1 && t->as_alg.wanted_el != t->a_num + t->b_num + 1) //spin in right direction and don't over spin if all els were moved
		{
			t->as_alg.curr_mid = (t->as_alg.curr_max - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
			if ((*a)->expected_pos > t->as_alg.curr_mid)
			{
				rotate(a, t, A);
				rotations++;
			}
			else
				push(a, b, t, B);
		}
		while (rotations--)
			r_rotate(a, t, A); // opt
		sort_b(a, b, t, t->as_alg.curr_mid);
		push_tagged_back(a, b, t);
	}
}