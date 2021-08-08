#include "push_swap.h"

static int	split_a(t_stack **a, t_stack **b, t_technical *t, int mid)
{
	int		rotations;
	int		k;

	k = (t->a_num + t->b_num) - t->as_alg.wanted_el + 1;
	rotations = 0;
	while (k--)
	{//rm
		if ((*a)->expected_pos > mid)
		{
			rotations++;
			rotate(a, t, A);
		}
		else
			push(a, b, t, B);
		print_ab(*a, *b, t);//rm
	} //rm
	return (rotations);
}

static void	align_a(t_stack **a, t_stack **b, t_technical *t, int k)
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
		{
			rotate(a, t, A);
			print_ab(*a, *b, t);// rm
			if ((*b)->expected_pos != t->as_alg.wanted_el)
			{// rm
				rotate(b, t, B);
				print_ab(*a, *b, t);// rm
			}// rm
		}
		else if (dir == DOWN)
		{
			r_rotate(a, t, A);
			print_ab(*a, *b, t);// rm
			if ((*b)->expected_pos != t->as_alg.wanted_el)
			{// rm
				r_rotate(b, t, B);
				print_ab(*a, *b, t); // rm
			}// rm
		}
}

static void	push_or_rotate(t_stack **a, t_stack **b, t_technical *t, int mid)
{
	if ((*b)->expected_pos == t->as_alg.wanted_el)
	{
		t->as_alg.wanted_el++;
		(*b)->curr_tag = SORTED;
		push(a, b, t, A);
		print_ab(*a, *b, t);
		rotate(a, t, A);
		print_ab(*a, *b, t);//rm
	}
	else if ((*b)->expected_pos < mid)
	{//rm
		rotate(b, t, B);
		print_ab(*a, *b, t);//rm
	}//rm
	else
	{
		(*b)->curr_tag = t->as_alg.global_tag;
		push(a, b, t, A);
		print_ab(*a, *b, t); //rm
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
	{//rm
		push(a, b, t, B);
		print_ab(*a, *b, t); //rm
	}//rm
}

void	asipes_algorithm(t_stack **a, t_stack **b, t_technical *t)
{
	int		max;
	int		mid;
	int 	rotations;

	mid = 0;
	max = t->a_num;
	while (mid < max)
	{
		mid = (max - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
		rotations = split_a(a, b, t, mid);
		align_a(a, b, t, rotations);
		split_b(a, b, t, mid);
		while ((*a)->curr_tag != DEFAULT && (*a)->curr_tag != SORTED)
		{
			move_tagged(a, b, t, (*a)->curr_tag);
			split_b(a, b, t, mid);
		}
	}
}