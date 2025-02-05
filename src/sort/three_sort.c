/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:42 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 09:20:48 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_sort(t_stack *stack)
{
	int	top;
	int	mid;
	int	last;

	top = stack->arr[stack->top];
	mid = stack->arr[stack->top - 1];
	last = stack->arr[0];
	if (stack_is_sorted(stack))
		return ;
	if (last > mid && last > top)
		swap(stack, SA);
	else if (top > mid && mid > last)
	{
		swap(stack, SA);
		reverse_rotate(stack, RRA);
	}
	else if (top > mid && top > last)
		rotate(stack, RA);
	else if (last < mid && last < top)
		reverse_rotate(stack, RRA);
	else if (top < mid && last < mid)
	{
		swap(stack, SA);
		rotate(stack, RA);
	}
}
