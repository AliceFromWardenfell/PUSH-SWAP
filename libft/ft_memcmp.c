/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:10 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:32:54 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_unc;

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int		rezult;
	size_t	index;

	index = 0;
	rezult = 0;
	while (index != n)
	{
		if (((t_unc *)str1)[index] != ((t_unc *)str2)[index])
		{
			rezult = ((t_unc *)str1)[index] - ((t_unc *)str2)[index];
			return (rezult);
		}
		index++;
	}
	return (rezult);
}
