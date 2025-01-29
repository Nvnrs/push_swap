/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:45:07 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/29 11:37:24 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/MYLIB42/mylib42.h"

#define MAX_INT_LENGTH 10
#define MIN_INT_STR "2147483648"
#define MAX_INT_STR "2147483647"

typedef struct	s_stack
{
	char	*arr;
	int		max;
	int		top;
}	t_stack;


typedef struct	s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct	s_tab_int
{
	int	*arr;
	int	max;
}	t_tab_int;

/* STACK */

int			pop(t_stack *stack);
t_bool		stack_empty(t_stack *stack);
int			top(t_stack *stack);
void		push(t_stack *stack, int nb);
t_bool		stack_is_full(t_stack *stack);
void		free_stack(t_stack *stack);
t_stack 	*init_stack(char nb_element);
t_stacks	*init_stacks(t_tab_int *tab_int);
void		free_stacks(t_stacks *stacks);

/* PARSING */
t_tab_int	*parse_data(int argc, char **argv);
t_bool		check_list_of_arg(int max_str, char **tab_str);
t_bool		only_val_in_tab(int nb_val, int *tab);
t_bool		comp_val_with_other(int i_val, int nb_val, int *tab);
t_tab_int	*conv_tab_strs_to_int(int nb_str, char **tab_str);
void		free_tab_int(t_tab_int *tab_int);

/* SORT */
void	sort(t_stacks *stacks);
#endif