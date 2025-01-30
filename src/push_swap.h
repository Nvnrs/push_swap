/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:45:07 by nveneros          #+#    #+#             */
/*   Updated: 2025/01/30 11:36:00 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/MYLIB42/mylib42.h"

#define MAX_INT_LENGTH 10
#define MIN_INT_STR "2147483648"
#define MAX_INT_STR "2147483647"

#define SA "sa\n"
#define SB "sb\n"
#define SS "sb\n"

#define PA "pa\n"
#define PB "pb\n"

#define RA "ra\n"
#define RB "rb\n"
#define RR "rr\n"

#define RRA "rra\n"
#define RRB "rrb\n"
#define RRR "rrr\n"


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

/* OPERATIONS */
void	swap(t_stack *stack, char *message);
void	swap_stacks(t_stacks *stacks);
void	push(t_stack *stack_src, t_stack *stack_dst, char *operation);
void	rotate(t_stack *stack, char *message);
void	rotate_stacks(t_stacks *stacks);
void	reverse_rotate(t_stack *stack, char *message);
void	reverse_rotate_stacks(t_stacks *stacks);

/*TEST OPERATIONS */
void	test_swap_stacks(t_stacks *stacks);
void	test_swap(t_stack *stack, char *message);
void	test_push(t_stack *stack_src, t_stack *stack_dst, char *operation);

/* STACK */

int			pop(t_stack *stack);
t_bool		stack_empty(t_stack *stack);
int			top(t_stack *stack);
void		stack_push(t_stack *stack, int nb);
t_bool		stack_is_full(t_stack *stack);
void		free_stack(t_stack *stack);
t_stack 	*init_stack(char nb_element);
t_stacks	*init_stacks(t_tab_int *tab_int);
void		free_stacks(t_stacks *stacks);
int			stack_len(t_stack *stack);
void		print_stack(t_stack *stack);
void		stack_push(t_stack *stack, int nb);

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