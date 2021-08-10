/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:15:38 by cvrone            #+#    #+#             */
/*   Updated: 2021/08/10 08:36:44 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*beyond_var(char **line, char **beyond, char **malloc_flag)
{
	char			*endl_ptr;

	endl_ptr = NULL;
	if (*beyond)
		if ((endl_ptr = ft_strchr(*beyond, '\n')))
		{
			endl_ptr[0] = '\0';
			if (!(*line = ft_strdup(*beyond)))
				return (*malloc_flag = NULL);
			ft_strcpy(*beyond, ++endl_ptr);
		}
		else
		{
			if (!(*line = ft_strdup(*beyond)))
				return (*malloc_flag = NULL);
			free(*beyond);
			*beyond = NULL;
		}
	else
	{
		if (!(*line = (char*)malloc(sizeof(char) * 1)))
			return (*malloc_flag = NULL);
		*line[0] = '\0';
	}
	return (endl_ptr);
}

int		core(int fd, char **line, char **beyond)
{
	int				read_ret;
	char			*buf;
	char			*endl_ptr;
	char			*tmp;
	char			*malloc_flag;

	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(*buf))))
		return (-1);
	read_ret = 0;
	malloc_flag = "true";
	endl_ptr = beyond_var(line, beyond, &malloc_flag);
	if (!*malloc_flag)
		return (-1);
	while (!endl_ptr && (read_ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_ret] = '\0';
		tmp = *line;
		if (ft_useless(&endl_ptr, buf, beyond, line) == -1)
			return (-1);
		free(tmp);
	}
	free(buf);
	return (read_ret || *beyond);
}

t_gnl	*new_el(int fd, char **line)
{
	t_gnl		*elem;
	char		buf[1];

	if (!(elem = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	elem->fd = fd;
	elem->beyond = NULL;
	elem->next = NULL;
	if (fd < 0 || line == NULL || (read(fd, buf, 0) == -1) || BUFFER_SIZE < 1)
	{
		free(elem);
		return (NULL);
	}
	return (elem);
}

void	ft_dellst(t_gnl **head, t_gnl *todel)
{
	t_gnl			*tmp;

	tmp = *head;
	if (*head == todel)
	{
		if ((*head)->next == NULL)
		{
			free(*head);
			*head = NULL;
		}
		else
		{
			*head = (*head)->next;
			free(tmp);
		}
	}
	else
	{
		while (tmp->next != todel)
			tmp = tmp->next;
		tmp->next = todel->next;
		free(todel);
	}
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	int				gnl_ret;

	if (head == NULL)
		if (!(head = new_el(fd, line)))
		{
			return (-1);
		}
	tmp = head;
	while (tmp->fd != fd)
	{
		if (!tmp->next)
			if (!(tmp->next = new_el(fd, line)))
				return (-1);
		tmp = tmp->next;
	}
	if ((gnl_ret = core(tmp->fd, line, &tmp->beyond)) < 1)
	{
		ft_dellst(&head, tmp);
	}
	return (gnl_ret);
}
