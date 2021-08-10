/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:56:19 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:38:28 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	sub = (char *)malloc((len + 1) * sizeof(*s));
	if (!sub)
		return (NULL);
	index = 0;
	while ((len != 0) && (s[start] != '\0'))
	{
		sub[index] = s[start];
		start++;
		index++;
		len--;
	}
	sub[index] = '\0';
	return (sub);
}
