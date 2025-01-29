/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:30:18 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/29 11:30:39 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	ft_printf("stack : ");
	if (stack_empty(stack))
	{
		ft_printf("empty");
		return ;
	}
	while (i >= 0)
	{
		if (i == 0)
			ft_printf("%d\n", stack->arr[i]);
		else
			ft_printf("%d, ", stack->arr[i]);
		i--;
	}
}