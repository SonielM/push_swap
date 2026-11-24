/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:09:05 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/24 19:32:16 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	swap_operation(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*a = second;
}

void	sa_operation(t_stack **a)
{
	swap_operation(a);
	write(1, "sa\n", 3);
}

void	sb_operation(t_stack **b)
{
	swap_operation(b);
	write(1, "sb\n", 3);
}

void	ss_operation(t_stack **a, t_stack **b)
{
	swap_operation(a);
	swap_operation(b);
	write(1, "ss\n", 3);
}
