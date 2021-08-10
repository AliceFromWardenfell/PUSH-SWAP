/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:12:06 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:38:10 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	unsigned int	index;

	index = ft_strlen(str);
	while (index != 0)
	{
		if (str[index] == chr)
			return ((char *)&str[index]);
		index--;
	}
	if (str[0] == chr)
		return ((char *)str);
	return (NULL);
}
