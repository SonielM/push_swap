/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahraou <sdahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 19:15:59 by sdahraou          #+#    #+#             */
/*   Updated: 2026/11/24 21:31:22 by sdahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
	int				rank;
}	t_stack;

int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
t_stack			*ft_lstnew(long content);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
void			clear_stack(t_stack **stack);
unsigned int	ft_lstsize(t_stack *stack);
t_stack			*create_stack(char **integers, int argc);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
void			sa_operation(t_stack **a);
void			sb_operation(t_stack **b);
void			ss_operation(t_stack **a, t_stack **b);
void			ra_operation(t_stack **a);
void			rb_operation(t_stack **b);
void			rr_operation(t_stack **a, t_stack **b);
void			rra_operation(t_stack **a);
void			rrb_operation(t_stack **a);
void			rrr_operation(t_stack **a, t_stack **b);
void			pa_operation(t_stack **b, t_stack **a);
void			pb_operation(t_stack **a, t_stack **b);
double			compute_disorder(t_stack *stack);
void			simple_algo(t_stack **a, t_stack **b);
int				ft_strcmp(const char *s1, const char *s2);
#endif
