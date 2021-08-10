#include "push_swap.h"

int	check_if_sorted(int	*arr, int size)
{
	int		sorted;

	sorted = 1;
	while (size--)
		if (arr[size] > arr[size + 1])
			sorted = 0;
	return (sorted);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_technical t;
	int			sorted;

	init(&a, &b, &t, argc); // handle init and clean; move them
	if (argc > 1)
	{
		// printf("Loading arguments into stack and array...\n");
		fill_stack_and_arr(&a, &t, argc, argv); // O(n^2)
		// printf("Stack and array has been successfully filled.\n");
		
		sorted = check_if_sorted(t.sorted_arr, t.a_num - 1);
		// print_arr(t.sorted_arr, t.a_num);s

		// printf("Sorting array...\n");
		heap_sort(t.sorted_arr, t.a_num);
		// printf("Array has been successfully sorted.\n");

		// printf("Checking on doubles...\n");
		check_doubles(t.sorted_arr, t.a_num - 1, sorted);
		// printf("Array has been successfully checked.\n");

		assign_expected_positions(a, &t);

		// print_ab(a, b, &t);

		// print_arr(t.original_arr, t.a_num);

		// printf("Trying 1st algorithm...\n");
		// radix_algorithm(&a, &b, &t);
		if (argc == 3)
			swap(&a, &t, A);
		if (argc == 4)
			sort_3(&a, &t, A);
		if (argc == 5)
			sort_4(&a, &b, &t, 1);
		if (argc == 6)
			sort_5(&a, &b, &t);
		if (argc > 6)
			asipes_algorithm(&a, &b, &t);
		// printf("1st algorithm has been successfully finished.\n");

		// print_ab(a, b, &t);

		inst_compress(t.inst);
		// printf("Instructions:\n"); // change ' ' on '\n' and remove '\n' in the end
		// printf("%s", t.instructions);
		print_instructions(t.inst);
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