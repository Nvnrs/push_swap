/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:37:29 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:06:11 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack, int operation)
{
	int	temp_top;

	if (operation != SS)
		message_operation(operation);
	if (stack_len(stack) < 2)
	{
		ft_printf("stack < 2");
		return ;
	}
	temp_top = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top -1];
	stack->arr[stack->top -1] = temp_top;
}

void	swap_stacks(t_stacks *stacks)
{
	swap(stacks->a, SS);
	swap(stacks->b, SS);
	message_operation(SS);
}
