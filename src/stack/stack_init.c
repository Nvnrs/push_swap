/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:25:44 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/01 18:55:42 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}

t_stack *init_stack(char nb_element)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return NULL;
	stack->arr = malloc(nb_element * sizeof(int));
	if (stack->arr == NULL)
		return NULL;
	stack->top = -1;
	stack->max = nb_element;
	return (stack);
}
