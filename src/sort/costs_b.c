/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:40:49 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/04 11:58:47 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


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

// void	get_costs_b(t_dynamic_tab *cost_b, t_stack *stack, int element)
// {
// 	int 	moves_top;
// 	int 	moves_bot;
// 	int 	minimal_moves_bot;
// 	int 	minimal_moves_top;

// 	// ft_printf("ELEMENT %d\n", element);
// 	// minimal_moves_top = 1;
// 	// minimal_moves_bot = 2;
// 	moves_top = count_move_start_top(cost_b, stack, element);
// 	moves_bot = count_move_start_bot(cost_b, stack, element);
	
// 	if (top_is_max(stack) && element > top(stack))
// 	{
// 		// ft_printf("top is max");
// 		cost_b->arr[cost_b->current_size++] = PB;
// 	}
// 	else if (last_is_min(stack) && element < stack->arr[0])
// 	{
// 		// ft_printf("last is min");
// 		cost_b->arr[cost_b->current_size++] = PB;
// 		cost_b->arr[cost_b->current_size++] = RB;
// 	}
// 	else
// 	{
// 		if (moves_top <= moves_bot)
// 		{
// 			int i;

// 			i = 0;
// 			// ft_printf("top is better\n");
// 			while (i < moves_top)
// 			{
// 				cost_b->arr[cost_b->current_size++] = RB;		
// 				i++;
// 			}
// 			cost_b->arr[cost_b->current_size++] = PB;
// 			cost_b->arr[cost_b->current_size++] = RB;	
// 		}
// 		else
// 		{
// 			int i;

// 			i = 0;
// 			// ft_printf("bot is better\n");	
// 			while (i < moves_bot)
// 			{
// 				cost_b->arr[cost_b->current_size++] = RRB;		
// 				i++;
// 			}
// 			cost_b->arr[cost_b->current_size++] = PB;
// 			cost_b->arr[cost_b->current_size++] = RB;		
// 		}

// 		// int i;

// 		// i = 0;
// 		// test_operation_b(copy_b,cost_b)
// 		// while (!top_is_max(copy_b))
// 		// 	cost_b->arr[cost_b->current_size++] = PB;	
		
// 	}
// }


/* NEW COST B */

int	index_element_in_stack(t_stack *stack, int element)
{
	int i;

	i = stack->top;
	while (i >= 0)
	{
		if (element == stack->arr[i])
			return (i);
		i--;
	}
	return (-1);
}


int	positive_subtraction(int n1, int n2)
{
	int result;

	result = n1 - n2;
	if (result < 0)
		result*= -1;
	return (result);
}

int	nearest_of_element(t_stack *stack, int element)
{
	int i;
	int nearest;
	int result;
	int last_result;

	i = stack->top;
	nearest = stack->arr[i];
	last_result = positive_subtraction(stack->arr[i], element);
	while (i >= 0)
	{
		result = positive_subtraction(stack->arr[i], element);
		if (result < last_result)
		{
			nearest = stack->arr[i];
			last_result = result;
		}
		i--;
	}
	return (nearest);
}

int	count_move_start_top(t_dynamic_tab *cost_b, t_stack *stack, int element, int nearest)
{
	int count;
	int i;

	count = 0;
	i = stack->top;
	// ft_printf("start TOP\n");
	while (i >= 0 && stack->arr[i] != nearest)
	{
		// ft_printf("%d < %d\n", element, stack->arr[start]);
		count++;
		i--;
	}
	return (count);
}


int	count_move_start_bot(t_dynamic_tab *cost_b, t_stack *stack, int element, int nearest)
{
	int i;
	int count;

	count = 0;
	i = 0;
	// ft_printf("start TOP\n");
	while (i < stack->top && stack->arr[i] != nearest)
	{
		// ft_printf("%d < %d\n", element, stack->arr[i]);
		count++;
		i++;
	}
	return (count);
}

void	get_costs_b(t_dynamic_tab *cost_b, t_stack *stack, int element, int i_el)
{
	int nearest;
	t_bool down;
	int middle_stack;

	nearest = nearest_of_element(stack, element);
	middle_stack = stack->top / 2;
	// ft_printf("NEAREST : %d\n", nearest);
	// ft_printf("stack before sort : ");
	// print_stack(stack);
	// UP / DOWN NEAREST
	down = FALSE;
	if (i_el >= middle_stack)
	{
		// remonter nearest / up nearest
		int move_from_top;
	
		move_from_top = count_move_start_top(cost_b, stack, element, nearest);
		while (move_from_top != 0)
		{
			cost_b->arr[cost_b->current_size++] = RB;
			move_from_top--;
		}
	}
	else
	{
		// descendre nearest
		int move_from_bot;
	
		move_from_bot = count_move_start_bot(cost_b, stack, element, nearest);
		// ft_printf("move bot %d", move_from_bot);
		down = TRUE;
		while (move_from_bot != 0)
		{
			cost_b->arr[cost_b->current_size++] = RRB;
			move_from_bot--;
		}

		// with opti
		if (element > nearest)
			cost_b->arr[cost_b->current_size++] = RRB;
		// // without
		// cost_b->arr[cost_b->current_size++] = RRB;
	}


	// if (down && element > nearest)
	// {

	// }
	// else if (down && element < nearest)
	// {
		
	// }

	// //  SORT OPTI
	if (element > nearest)
	{
		cost_b->arr[cost_b->current_size++] = PB;
		// cost_b->arr[cost_b->current_size++] = RB;
	}
	else if (element < nearest)
	{
		if (!down)
			cost_b->arr[cost_b->current_size++] = RB;
		cost_b->arr[cost_b->current_size++] = PB;
	}
	//  SORT without opti
	// if (element > nearest)
	// {
	// 	cost_b->arr[cost_b->current_size++] = PB;
	// 	cost_b->arr[cost_b->current_size++] = RB;
	// }
	// else if (element < nearest)
	// {
	// 	cost_b->arr[cost_b->current_size++] = RB;
	// 	cost_b->arr[cost_b->current_size++] = PB;
	// }
}
