/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 20:34:42 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/24 19:32:28 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	free_split(char **integers, int argc)
{
	int	i;

	if (argc != 2 || !integers)
		return ;
	i = 0;
	while (integers[i])
		free(integers[i++]);
	free(integers);
}

static char	**get_args(char **argv, int argc, int *start)
{
	if (argc == 2)
	{
		*start = 0;
		return (ft_split(argv[1], ' '));
	}
	*start = 1;
	return (argv);
}

t_stack	*create_stack(char **argv, int argc)
{
	t_stack	*stack;
	t_stack	*node;
	char	**integers;
	int		i;

	if (!argv || argc <= 1)
		return (NULL);
	integers = get_args(argv, argc, &i);
	if (!integers || !integers[i])
		return (free_split(integers, argc), NULL);
	stack = ft_lstnew(ft_atoi(integers[i++]));
	if (!stack)
		return (free_split(integers, argc), NULL);
	while (integers[i])
	{
		node = ft_lstnew(ft_atoi(integers[i++]));
		if (!node)
			return (clear_stack(&stack), free_split(integers, argc), NULL);
		ft_lstadd_back(&stack, node);
	}
	free_split(integers, argc);
	return (stack);
}

unsigned int	ft_lstsize(t_stack *stack)
{
	unsigned int	size;
	t_stack			*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
