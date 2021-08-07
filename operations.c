#include "push_swap.h"

static void	ft_realloc(t_technical *t)
{
	char	*old;

	t->amount_of_allmem += t->amount_of_allmem / 10;
	old = t->instructions;
	t->instructions = (char *)malloc(t->amount_of_allmem);
	printf("using %d bytes\n", t->last_inst_position); //rm
	printf("allocated %d bytes\n", t->amount_of_allmem); //rm
	if (!t->instructions)
		exit(error());
	ft_memcpy(t->instructions, old, t->last_inst_position);
	free(old);
}

void	write_instructions(t_technical *t, char *instruction)
{
	int		inst_len;

	t->amount_of_instructions++;
	if (t->last_inst_position >= t->amount_of_allmem)
		ft_realloc(t);
	inst_len = ft_strlen(instruction) * sizeof(char);
	ft_memcpy(&(t->instructions[t->last_inst_position]), instruction, inst_len); //rm ()
	t->last_inst_position += inst_len;
	t->instructions[t->last_inst_position] = '\0';
}

void	rotate(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;

	if (stack == A)
		write_instructions(t, RA);
	else if (stack == B)
		write_instructions(t, RB);
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
		write_instructions(t, RRA);
	else if (stack == B)
		write_instructions(t, RRB);
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
		write_instructions(t, PA);
	}
	else if (stack == B && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		t->a_num--;
		t->b_num++;
		write_instructions(t, PB);
	}
}


void	swap(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;
	
	if (stack == A)
		write_instructions(t, SA);
	else if (stack == B)
		write_instructions(t, SB);
	if (t->a_num < 2)
		return ;
	tmp = *a;
	tmp = tmp->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

