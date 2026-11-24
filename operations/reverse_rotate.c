/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:04:27 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/24 19:32:07 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	reverse_rotate_operation(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra_operation(t_stack **a)
{
	reverse_rotate_operation(a);
	write(1, "rra\n", 4);
}

void	rrb_operation(t_stack **b)
{
	reverse_rotate_operation(b);
	write(1, "rrb\n", 4);
}

void	rrr_operation(t_stack **a, t_stack **b)
{
	reverse_rotate_operation(a);
	reverse_rotate_operation(b);
	write(1, "rrr\n", 4);
}
