/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:30:49 by nveneros          #+#    #+#             */
/*   Updated: 2025/02/05 08:37:31 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack_src, t_stack *stack_dst, int operation)
{
	message_operation(operation);
	if (stack_empty(stack_src))
		return ;
	stack_push(stack_dst, top(stack_src));
	pop(stack_src);
}
