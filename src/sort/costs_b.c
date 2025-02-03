/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:40:49 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/03 15:19:56 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	count_move_start_top(t_dynamic_tab *cost_b, t_stack *stack, int element)
{
	int count;
	int start;

	count = 0;
	start = stack->top;
	// ft_printf("start TOP\n");
	while (start >= 0 && element < stack->arr[start])
	{
		// ft_printf("%d < %d\n", element, stack->arr[start]);
		count++;
		start--;
	}
	return (count);
}


int	count_move_start_bot(t_dynamic_tab *cost_b, t_stack *stack, int element)
{
	int count;
	int start;

	count = 0;
	start = 0;
	// ft_printf("start BOT\n");
	while (start <= stack->top && element > stack->arr[start])
	{
		// ft_printf("%d > %d\n", element, stack->arr[start]);
		count++;
		start++;
	}
	return (count);
}

t_bool	top_is_max(t_stack *stack)
{
	int i;
	int val_top;

	i = stack->top -1;
	val_top = top(stack);
	while (i >= 0)
	{
		if (stack->arr[i] > val_top)
			return (FALSE);
		i--;
	}
	return (TRUE);
}

t_bool	last_is_min(t_stack *stack)
{
	int i;
	int val_last;

	i = stack->top;
	val_last = stack->arr[0];
	while (i > 0)
	{
		if (stack->arr[i] < val_last)
			return (FALSE);
		i--;
	}
	return (TRUE);
}

// void	test_operations_b(t_dynamic_tab *cost_b, t_stacks *stacks)
// {
// 	int 	i;
// 	int 	operation;
// 	t_stack *copy_b;
// 	t_stack *copy_a;

// 	i = 0;
// 	copy_a = stack_copy(stacks->a)
// 	copy_b = stack_copy(stacks->b)
// 	while (i < cost_b->current_size)
// 	{
// 		operation = cost_b->arr[i];
// 		if (operation == RB)
// 			rotate(copy_b, 0);
// 		else if (operation == RRB)
// 			reverse_rotate(copy_b, 0);
// 		else if (operation == PB)
// 			push()
// 		i++;
// 	}
	
// }
void	get_costs_b(t_dynamic_tab *cost_b, t_stack *stack, int element)
{
	int 	moves_top;
	int 	moves_bot;
	int 	minimal_moves_bot;
	int 	minimal_moves_top;

	// ft_printf("ELEMENT %d\n", element);
	// minimal_moves_top = 1;
	// minimal_moves_bot = 2;
	moves_top = count_move_start_top(cost_b, stack, element);
	moves_bot = count_move_start_bot(cost_b, stack, element);

	if (top_is_max(stack) && element > top(stack))
	{
		// ft_printf("top is max");
		cost_b->arr[cost_b->current_size++] = PB;
	}
	else if (last_is_min(stack) && element < stack->arr[0])
	{
		// ft_printf("last is min");
		cost_b->arr[cost_b->current_size++] = PB;
		cost_b->arr[cost_b->current_size++] = RB;
	}
	else
	{
		if (moves_top <= moves_bot)
		{
			int i;

			i = 0;
			while (i < moves_top)
			{
				cost_b->arr[cost_b->current_size++] = RB;		
				i++;
			}
			cost_b->arr[cost_b->current_size++] = PB;
			cost_b->arr[cost_b->current_size++] = RB;	
		}
		else
		{
			int i;

			i = 0;
			while (i < moves_bot)
			{
				cost_b->arr[cost_b->current_size++] = RRB;		
				i++;
			}
			cost_b->arr[cost_b->current_size++] = PB;
			cost_b->arr[cost_b->current_size++] = RB;		
		}

		// int i;

		// i = 0;
		// test_operation_b(copy_b,cost_b)
		// while (!top_is_max(copy_b))
		// 	cost_b->arr[cost_b->current_size++] = PB;	
		
	}
}
