/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:52:23 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:32:35 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t n)
{
	size_t	index;

	index = 0;
	while (index != n)
	{
		if (((unsigned char *)str)[index] == (unsigned char)chr)
			return ((void *)(str + index));
		index++;
	}
	return (NULL);
}
