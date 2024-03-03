/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:21:56 by tle-monn          #+#    #+#             */
/*   Updated: 2024/02/26 13:34:47 by tle-monn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head) //function that swap the top node and the second node
{
	if(!*head || !(*head)->next) //check if top node or second nnode exists
		return ;
	*head = (*head)->next; //update head to popint the next node
	(*head)->prev->prev = *head; //update the prev pointer before the new head to point to the new head
	(*head)->prev->next = (*head)->next; //update the next pointer before the new head to skip the old head qnd point directly to the new head
	if ((*head)->next) // check if there a next node after the new head
		(*head)->next->prev = (*head)->prev;//update its prev pointer to point back to the new head
	(*head)->next = (*head)->prev; // updqte the next pointer of new head to point to the old head
	(*head)->prev = NULL; //set the prev pointer to null
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if(!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if(!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if(!print)
		ft_printf("ss\n");
}

