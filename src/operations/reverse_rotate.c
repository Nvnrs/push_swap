/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:24 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/01 17:52:53 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 1. rra (reverse rotate a)
//   * Décale tous les éléments de la pile A d'une position vers le bas.
// Le dernier élément devient le premier.
// 2. rrb (reverse rotate b)
//   * Décale tous les éléments de la pile B d'une position vers le bas.
// Le dernier élément devient le premier.
// 3. rrr
//   * Applique rra et rrb simultanément.

void	reverse_rotate(t_stack *stack, int operation)
{
	int i;
	int temp;

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