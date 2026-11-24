/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:33:38 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/24 20:57:08 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	push_top(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (!src || !dst || !*src)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = NULL;
	ft_lstadd_front(dst, node);
}

void	pa_operation(t_stack **b, t_stack **a)
{
	push_top(b, a);
	write(1, "pa\n", 3);
}

void	pb_operation(t_stack **a, t_stack **b)
{
	push_top(a, b);
	write(1, "pb\n", 3);
}
