/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:00:10 by tle-monn          #+#    #+#             */
/*   Updated: 2024/02/21 21:01:29 by tle-monn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n) //handle error with return 0 or 1
{
	if(!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9'))) // check first char isnt digit or sign
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9')) // check first char is sign but the second isnt digit
		return (1);
	while (*++str_n) //if error above passed, pre increment to the next char and loop until the end
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //check if the next char is a digit
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n) //check if duplicate input in stack a
{
	if (!a) //check empty stack
		return (0);
	while (a) //loop until the end of the stack a
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack) //function to free a stack if error
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if(!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a) //function that free the stack and print error message
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
