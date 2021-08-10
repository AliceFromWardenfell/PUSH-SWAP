/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:35:55 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:37:01 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*rez;

	if (!s || !f)
		return (NULL);
	rez = (char *)malloc((ft_strlen(s) + 1) * sizeof(*rez));
	if (!rez)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		rez[index] = f(index, s[index]);
		index++;
	}
	rez[index] = '\0';
	return (rez);
}
