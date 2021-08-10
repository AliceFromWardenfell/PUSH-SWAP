/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:50:28 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:34:06 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int val, size_t n)
{
	unsigned int	index;

	index = 0;
	while (index != n)
	{
		((char *)str)[index] = val;
		index++;
	}
	return (str);
}
