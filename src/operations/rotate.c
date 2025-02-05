/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:23:42 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:06:36 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack, int operation)
{
	int	i;
	int	temp;

	i = stack->top;
	if (operation != RR)
		message_operation(operation);
	while (i > 0)
	{
		temp = stack->arr[i];
		stack->arr[i] = stack->arr[i -1];
		stack->arr[i -1] = temp;
		i--;
	}
}

void	rotate_stacks(t_stacks *stacks)
{
	rotate(stacks->a, RR);
	rotate(stacks->b, RR);
	message_operation(RR);
}
