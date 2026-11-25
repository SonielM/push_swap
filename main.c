/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 19:15:55 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/25 15:56:50 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	test(t_stack **a, t_stack **b)
// {
// 	sa_operation(a);
// 	pb_operation(a, b);
// 	pb_operation(a, b);
// 	ra_operation(a);
// 	rb_operation(b);
// 	rr_operation(a, b);
// 	rra_operation(a);
// 	rrb_operation(b);
// 	rrr_operation(a, b);
// }

static void	node_inversions(t_stack *node, double *mistakes, double *pairs)
{
	t_stack	*next_node;

	next_node = node->next;
	while (next_node)
	{
		*pairs += 1.0;
		if (node->value > next_node->value)
			*mistakes += 1.0;
		next_node = next_node->next;
	}
}

double	compute_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;

	if (!stack || !stack->next)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	while (stack->next)
	{
		node_inversions(stack, &mistakes, &total_pairs);
		stack = stack->next;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (1);
	stack_b = NULL;
	stack_a = create_stack(argv, argc);
	printf("the disorder of the stack is : %f\n", compute_disorder(stack_a));
	simple_algo(&stack_a, &stack_b);
	while (stack_a)
	{
		printf("values of stack a : %ld\n", stack_a->value);
		stack_a = stack_a->next;
	}
	return (0);
}
