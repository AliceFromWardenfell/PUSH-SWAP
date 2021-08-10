/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:18:49 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:35:25 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	unsigned int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == chr)
			return ((char *)&str[index]);
		index++;
	}
	if (chr == '\0')
		return ((char *)&str[index]);
	return (NULL);
}
