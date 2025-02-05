/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:24 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:07:13 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack, int operation)
{
	int	i;
	int	temp;

	i = 0;
	if (operation != RRR)
		message_operation(operation);
	while (i < stack->top)
	{
		temp = stack->arr[i];
		stack->arr[i] = stack->arr[i + 1];
		stack->arr[i + 1] = temp;
		i++;
	}
}

void	reverse_rotate_stacks(t_stacks *stacks)
{
	reverse_rotate(stacks->a, RRR);
	reverse_rotate(stacks->b, RRR);
	message_operation(RRR);
}
