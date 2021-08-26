/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:48:12 by alisa             #+#    #+#             */
/*   Updated: 2021/08/26 22:14:52 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, int *arr)
{
	int		i;

	i = 0;
	while (a)
	{
		if (a->val != arr[i])
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

void	check_doubles(int *arr, int size, int sorted)
{
	while (size--)
		if (arr[size] == arr[size + 1])
			exit(error());
	if (sorted)
		exit(0);
}

static void	check_signs(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '+' && str[0] != '-' && !ft_isdigit(str[0]))
		exit(error());
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		exit(error());
	while (str[++i])
		if (!ft_isdigit(str[i]))
			exit(error());
}

int	check_argv(char *str)
{
	long int	val;

	check_signs(str);
	val = ft_atoi(str);
	if (val > 2147483647 || val < -2147483648)
		exit(error());
	return ((int)val);
}
