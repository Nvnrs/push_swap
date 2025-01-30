/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:15:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/30 11:45:10 by nveneros         ###   ########.fr       */
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
		return ;
	if (stacks->a->max == 3)
	{
		ft_printf("use _algo for 3\n");
		return;
	}
	// ft_printf("len stack A : %d\n", stack_len(stacks->a));
	// ft_printf("len stack B : %d\n", stack_len(stacks->b));
}