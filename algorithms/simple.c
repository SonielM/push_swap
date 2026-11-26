/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:09:11 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/25 16:08:18 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static long	get_minimum(t_stack *a)
{
	long	min;

	if (!a)
		return (0);
	min = a->value;
	a = a->next;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	simple_algo(t_stack **a, t_stack **b)
{
	long	min;

	if (!a || !b || !*a)
		return ;
	while (*a)
	{
		min = get_minimum(*a);
		while ((*a)->value != min)
			rra_operation(a);
		pb_operation(a, b);
	}
	while (*b)
		pa_operation(b, a);
}
