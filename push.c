/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:46:39 by tle-monn          #+#    #+#             */
/*   Updated: 2024/02/26 14:12:32 by tle-monn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src) //function that pushes a top node fro; one stack to another top node
{
	t_stack_node *push_node;

	if(!*src)
		return ;
	push_node = *src;
	*src = (*src)->next; //move the pointer to the next node
	if(*src)
		(*src)->prev = NULL; //set the current node as the head
	push_node->prev = NULL; //detach the node to push from its stack
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print) //push on top of b, the top a and print
{
	push(a, b);
	if(!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print) //push on top of a, the top b and print
{
	push(b, a);
	if(!print)
		ft_printf("pb\n");
}
