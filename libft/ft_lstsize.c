/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvrone <cvrone@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:24:50 by cvrone            #+#    #+#             */
/*   Updated: 2020/12/09 22:36:32 by cvrone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*tmp;

	if (!lst)
		return (0);
	n = 1;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}
