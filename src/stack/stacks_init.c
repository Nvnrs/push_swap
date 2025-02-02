/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:50:37 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/01 18:52:26 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(t_stack *stack_a, int *tab_int)
{
	int	i;

	i = stack_a->max -1;
	while (i >= 0)
	{
		stack_push(stack_a, tab_int[i]);
		i--;
	}
}

void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}

void	*handle_error_stacks(t_stacks *stacks)
{
	if (stacks->a != NULL)
		free_stack(stacks->a);
	if (stacks->b != NULL)
		free_stack(stacks->b);
	if (stacks != NULL)
		free(stacks);
	return (NULL);
}

t_stacks	*init_stacks(t_tab_int *tab_int)
{
	t_stacks	*stacks;

	stacks = malloc (sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = init_stack(tab_int->max);
	if (stacks->a == NULL)
		return (handle_error_stacks(stacks));
	stacks->b = init_stack(tab_int->max);
	if (stacks->b == NULL)
		return (handle_error_stacks(stacks));
	fill_stack(stacks->a, tab_int->arr);
	return (stacks);
}
