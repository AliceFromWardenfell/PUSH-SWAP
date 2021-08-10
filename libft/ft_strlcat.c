/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:59:02 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:36:43 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	prime_len_dst;

	index = 0;
	prime_len_dst = (size_t)ft_strlen(dst);
	if (size <= (size_t)ft_strlen(dst))
		return (size + (size_t)ft_strlen(src));
	while (src[index] != '\0'
		&& (index + prime_len_dst) < (size - 1))
	{
		dst[index + prime_len_dst] = src[index];
		index++;
	}
	dst[index + prime_len_dst] = '\0';
	return ((size_t)ft_strlen(src) + prime_len_dst);
}
