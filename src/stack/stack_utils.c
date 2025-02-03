/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:30:18 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/03 10:37:31 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	if (stack_empty(stack))
	{
		ft_printf("empty\n");
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

t_stack *stack_copy(t_stack *stack)
{
	t_stack *copy;
	int 	i;

	i = stack->top;
	copy = init_stack(stack->max);
	copy->top = i;
	if (copy == NULL)
		return (NULL);
	while (i >= 0)
	{
		copy->arr[i] = stack->arr[i];
		i--;
	}
	return (copy);
}

int	stack_len(t_stack *stack)
{
	int i;
	int len;

	i = stack->top;
	len = 0;
	if (stack_empty(stack))
		return (len);
	while (i >= 0)
	{
		len++;
		i--;
	}
	return (len);
}