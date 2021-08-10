/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:00:17 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:36:22 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(const char *str)
{
	return (ft_strlen(str));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	index = 0;
	while (index != len(s1))
	{
		join[index] = s1[index];
		index++;
	}
	while (index != len(s1) + len(s2))
	{
		join[index] = s2[index - len(s1)];
		index++;
	}
	join[index] = '\0';
	return (join);
}
