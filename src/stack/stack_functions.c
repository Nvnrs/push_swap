/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:23:55 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 16:02:06 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	stack_is_full(t_stack *stack)
{
	if (stack->top == stack->max -1)
		return (TRUE);
	return (FALSE);
}

void	stack_push(t_stack *stack, int nb)
{
	if (stack_is_full(stack))
	{
		ft_printf("stack is full for %d\n", nb);
		return ;
	}
	stack->top++;
	stack->arr[stack->top] = nb;
}

int	top(t_stack *stack)
{
	return (stack->arr[stack->top]);
}

t_bool	stack_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (TRUE);
	return (FALSE);
}

int	pop(t_stack *stack)
{
	int popped;

	if (stack_empty(stack))
	{
		ft_printf("stack is empty\n");
		return (-1);
	}
	popped = stack->arr[stack->top];
	stack->top--;
	return (popped);
}
