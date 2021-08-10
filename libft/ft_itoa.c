/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:00:03 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:31:38 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	rev_ass(char *rez, int n, int len)
{
	if (len != -1)
	{
		rev_ass(rez, n / 10, len - 1);
		rez[len] = n % 10 + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*rez;

	rez = (char *)malloc(sizeof(*rez) * (len(n) + 1));
	if (!rez)
		return (NULL);
	rez[len(n)] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			rev_ass(rez, 2147483647, len(n) - 1);
			rez[10] = '8';
		}
		else
			rev_ass(rez, -n, len(n) - 1);
		rez[0] = '-';
	}
	else
		rev_ass(rez, n, len(n) - 1);
	return (rez);
}
