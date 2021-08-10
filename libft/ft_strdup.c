/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:41:58 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:35:46 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	index;
	char			*cp;

	cp = (char *)malloc((ft_strlen(str) + 1) * sizeof(*str));
	if (!cp)
		return (NULL);
	index = 0;
	while (index != ft_strlen(str))
	{
		cp[index] = str[index];
		index++;
	}
	cp[index] = '\0';
	return (cp);
}
