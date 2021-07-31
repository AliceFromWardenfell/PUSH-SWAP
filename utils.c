#include "push_swap.h"

void	print_list(t_stack *a, t_technical *t, int stack)
{
	if (stack == A)
		printf("A: ");
	else if (stack == B)
		printf("B: ");
	printf("HEAD ");
	while(a)
	{
		printf("%d ", a->val);
		a = a->next;
	}
	printf("TAIL ");
	if (stack == A)
		printf("(%d)\n", t->a_num);
	else if (stack == B)
		printf("(%d)\n", t->b_num);
}

void	print_ab(t_stack *a, t_stack *b, t_technical *t)
{
	print_list(a, t, A);
	print_list(b, t, B);
	printf("\n");
}