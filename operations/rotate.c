/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:12:16 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/24 19:32:12 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	rotate_operation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra_operation(t_stack **a)
{
	rotate_operation(a);
	write(1, "ra\n", 3);
}

void	rb_operation(t_stack **b)
{
	rotate_operation(b);
	write(1, "rb\n", 3);
}

void	rr_operation(t_stack **a, t_stack **b)
{
	rotate_operation(a);
	rotate_operation(b);
	write(1, "rr\n", 3);
}
