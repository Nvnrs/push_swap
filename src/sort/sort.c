/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:15:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 16:42:11 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	stack_is_sorted(t_stack *stack)
{
	int i;
	int curr;
	int next;

	i = stack->top;
	while (i > 0)
	{
		curr = stack->arr[i];
		next = stack->arr[i - 1];
		if (curr > next)
			return (FALSE);
		i --;
	}
	return (TRUE);
}


void	sort(t_stacks *stacks)
{
	if (stack_is_sorted(stacks->a))
		ft_printf("stacks is sorted");
	else if (stacks->a->max == 2)
		rotate(stacks->a, RA);
	else if (stacks->a->max == 3)
	{
		three_sort(stacks->a);
		print_stack(stacks->a);
		return;
	}
	else
		turk_sort(stacks);
}
