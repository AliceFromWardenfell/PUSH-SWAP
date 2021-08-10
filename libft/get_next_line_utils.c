/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:51:01 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 07:40:35 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *dest, char *src)
{
	unsigned int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

int	ft_useless(char **endl_ptr, char *buf, char **beyond, char **line)
{
	*endl_ptr = ft_strchr(buf, '\n');
	if (*endl_ptr)
	{
		*endl_ptr[0] = '\0';
		(*endl_ptr)++;
		*beyond = ft_strdup(*endl_ptr);
		if (!*beyond)
			return (-1);
	}
	*line = ft_strjoin_m(*line, buf, 0, 0);
	if (!*line)
	{
		if (*beyond != NULL)
			free(*beyond);
		return (-1);
	}
	return (0);
}

char	*ft_strjoin_m(const char *s1, const char *s2, int len1, int len2)
{
	int				index;
	char			*join;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	join = malloc((len1 + len2 + 1) * sizeof(*s1));
	if (!join)
		return (NULL);
	index = 0;
	while (index != len1)
	{
		join[index] = s1[index];
		index++;
	}
	while (index != len1 + len2)
	{
		join[index] = s2[index - len1];
		index++;
	}
	join[index] = '\0';
	return (join);
}

char	*ft_strdup(const char *str)
{
	int				index;
	char			*cp;
	int				len;

	len = 0;
	while (str[len] != '\0')
		len++;
	cp = (char *)malloc((len + 1) * sizeof(*str));
	if (!cp)
		return (NULL);
	index = 0;
	while (index != len)
	{
		cp[index] = str[index];
		index++;
	}
	cp[index] = '\0';
	return (cp);
}

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
