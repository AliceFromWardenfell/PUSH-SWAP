#include "push_swap.h"

void	write_instructions(t_technical *t, char *instruction)
{
	char	*old;

	old = t->instructions;
	t->instructions = ft_strjoin(t->instructions, instruction); 
	if (!t->instructions)
		exit(error());
	free(old);
}

void	rotate(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;

	if (stack == A)
		write_instructions(t, RA); // change ' ' on '\n'
	else if (stack == B)
		write_instructions(t, RB); // change ' ' on '\n'
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	(*a) = tmp->next;
	tmp->next = NULL;
}

void	r_rotate(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (stack == A)
		write_instructions(t, RRA); // change ' ' on '\n'
	else if (stack == B)
		write_instructions(t, RRB); // change ' ' on '\n'
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	head = *a;
	while (tmp->next)
	{
		*a = tmp->next;
		if (!(*a)->next)
		{
			tmp->next = NULL;
			(*a)->next = head;
		}
		else
			tmp = tmp->next;
	}
}

void	push(t_stack **a, t_stack **b, t_technical *t, int stack)
{
	t_stack	*tmp;

	if (stack == A && *b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		t->b_num--;
		t->a_num++;
		write_instructions(t, PA); // change ' ' on '\n'
	}
	else if (stack == B && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		t->a_num--;
		t->b_num++;
		write_instructions(t, PB); // change ' ' on '\n'
	}
}


void	swap(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;
	
	if (stack == A)
		write_instructions(t, SA); // change ' ' on '\n'
	else if (stack == B)
		write_instructions(t, SB); // change ' ' on '\n'
	if (t->a_num < 2)
		return ;
	tmp = *a;
	tmp = tmp->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

