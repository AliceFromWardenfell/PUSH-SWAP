/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:49:32 by alisa             #+#    #+#             */
/*   Updated: 2021/08/26 22:02:53 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **a, t_stack **b, t_technical *t)
{	
	*a = NULL;
	*b = NULL;
	t->as_alg.global_tag = 0;
	t->as_alg.wanted_el = 1;
	t->sorted_arr = NULL;
	t->inst = NULL;
	t->inst_ch = NULL;
}

void	print_instructions(t_inst *inst)
{
	while (inst)
	{
		ft_putstr(inst->instruction);
		inst = inst->next;
	}
}
