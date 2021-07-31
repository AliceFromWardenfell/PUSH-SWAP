#include "push_swap.h"

static void	check_doubles(t_stack *a, int val) // mb improve O(n)
{
	while (a && a->next)
	{
		a = a->next;
		if (a->val == val)
			exit(error());
	}
}

static void	check_signs(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '+' && str[0] != '-' && !ft_isdigit(str[0]))
		exit(error());
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		exit(error());
	if (str[0] == '+' || str[0] == '-')
		while (str[++i])
			if (!ft_isdigit(str[i]))
				exit(error());
}

int		check_argv(t_stack *a, char *str)
{
	long int	val;

	check_signs(str);
	val = ft_atoi(str);
	if (val > 2147483647 || val < -2147483648)
		exit(error());
	check_doubles(a, (int)val);
	return ((int)val);
}
