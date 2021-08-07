#include "push_swap.h"

static void	fill_stack_and_arr(t_stack **a, t_technical *t, int argc, char **argv)
{
	int		i;
	int		checked_val;

	i = 1;
	t->original_arr = (int *)malloc((argc - 1) * sizeof(int)); //rm
	t->sorted_arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!t->sorted_arr)
		exit(error());
	*a = create_node(check_argv(*a, argv[i]));
	t->sorted_arr[i - 1] = check_argv(*a, argv[i]);
	t->original_arr[i - 1] = t->sorted_arr[i - 1]; //rm
	while (++i < argc)
	{
		checked_val = check_argv(*a, argv[i]);
		addnode_back(a, create_node(checked_val));
		t->sorted_arr[i - 1] = checked_val;
		t->original_arr[i - 1] = t->sorted_arr[i - 1]; //rm
	}
	t->a_num = i - 1;
	t->b_num = 0;
}

void	init(t_stack **a, t_stack **b, t_technical *t)
{	
	*a = NULL;
	*b = NULL;
	t->as_alg.global_tag = 0;
	t->as_alg.wanted_el = 1;
	t->instructions = malloc(sizeof(char)); // !!!
	if (!t->instructions)
		exit(error());
	*t->instructions = '\0';
}

void	assign_expected_positions(t_stack *a, t_technical *t)
{
	int		i;

	while (a)
	{
		i = 0;
		while ((a)->val != t->sorted_arr[i])
			i++;
		(a)->expected_pos = i + 1;
		a = (a)->next;
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_technical t;

	init(&a, &b, &t);
	if (argc > 1)
	{
		// printf("Loading arguments into stack and array...\n");
		fill_stack_and_arr(&a, &t, argc, argv); // O(n^2)
		// printf("Stack and array has been successfully filled.\n");

		// print_arr(t.sorted_arr, t.a_num);

		// printf("Sorting array...\n");
		heap_sort(t.sorted_arr, t.a_num);
		assign_expected_positions(a, &t);
		// printf("Array has been successfully sorted.\n");

		// printf("Checking on doubles...\n");
		check_doubles(t.sorted_arr, t.a_num);
		// printf("Array has been successfully checked.\n");

		// print_ab(a, b, &t);

		// print_arr(t.original_arr, t.a_num);

		// printf("Trying 1st algorithm...\n");
		// radix_algorithm(&a, &b, &t);

		asipes_algorithm(&a, &b, &t);
		// printf("1st algorithm has been successfully finished.\n");
		
		// print_ab(a, b, &t);

		// printf("Instructions:\n"); // change ' ' on '\n' and remove '\n' in the end
		// printf("%s", t.instructions);
	}
	clean(&a, &b, &t);
	// leaks
	return (0);
}
// r_rotate(&a, &t, A);
// rotate(&b, &t, B);
// swap(&b, &t, B);
// push(&a, &b, &t, B);
// print_ab(a, b, &t);