/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:30:49 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/01 17:45:09 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 1. pa (push a)
//   * Prend le premier élément de la pile B et le place au sommet de la pile A.
//   * Si la pile B est vide, l'instruction n'a aucun effet.
// 2. pb (push b)
//   * Prend le premier élément de la pile A et le place au sommet de la pile B.
//   * Si la pile A est vide, l'instruction n'a aucun effet.

void	test_push(t_stack *stack_src, t_stack *stack_dst, int operation)
{
	ft_printf("SRC BEFORE :");
	print_stack(stack_src);
	ft_printf("DEST BEFORE :");
 	print_stack(stack_dst);
	push(stack_src, stack_dst, operation);
	ft_printf("SRC AFTER :");
	print_stack(stack_src);
	ft_printf("DEST AFTER :");
 	print_stack(stack_dst);
}

void	push(t_stack *stack_src, t_stack *stack_dst, int operation)
{
	message_operation(operation);
	if (stack_empty(stack_src))
		return ;
	stack_push(stack_dst, top(stack_src));
	pop(stack_src);
}
