#include "push_swap.h"

void	fill_stack(t_stack **a, t_technical *t, int argc, char **argv)
{
	int		i;

	i = 1;
	*a = create_node(check_argv(*a, argv[i]));
	while (++i < argc)
		addnode_back(a, create_node(check_argv(*a, argv[i])));
	t->a_num = i - 1;
	t->b_num = 0;
}

void	init(t_stack **a, t_stack **b, t_technical *t)
{
	*a = NULL;
	*b = NULL;
	t->instructions = malloc(sizeof(char)); // !!!
	if (!t->instructions)
		exit(error());
	*t->instructions = '\0';
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_technical t;

	init(&a, &b, &t);
	if (argc > 1)
	{
		fill_stack(&a, &t, argc, argv);
		// print_ab(a, b, &t);

		alg1(&a, &b, &t);
		// print_ab(a, b, &t);

		// printf("Instructions:\n"); // change ' ' on '\n' and remove '\n' in the end
		printf("%s", t.instructions);
	}
	// leaks
	return (0);
}
// r_rotate(&a, &t, A);
// rotate(&b, &t, B);
// swap(&b, &t, B);
// push(&a, &b, &t, B);
// print_ab(a, b, &t);