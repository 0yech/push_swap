/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:39:25 by cheyo             #+#    #+#             */
/*   Updated: 2024/11/01 18:48:31 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* main.c */
int		main(int argc, char **argv);

/* validation.c */
int		valid_args(int argc, char **argv);

/* initialization.c */
int		init_nums(char **argv, int **numbers, int *total_numbers);

/* args_utils.c */
int		splitcount(char *arg);
int		countargs(char **argv);
int		process_argument(char *arg, int *numbers, int *k);
int		process_single_argument(char *arg, int *numbers, int *k);
int		process_split_argument(char *arg, int *numbers, int *k);

/* numbers_utils.c */
int		fill_nums(char **argv, int *numbers);
int		get_total_nums(char **argv);
int		allocate_nums(int **numbers, int total_numbers);
int		fill_numbers_wrapper(char **argv, int *numbers);
int		check_duplicates_wrapper(int *numbers, int total_numbers);

/* parsing.c */
int		parsecheck(int argc, char **argv);
int		checkargs(char **args);
int		checkvalidity(char *s);

/* utils.c */
long	ft_longatoi(const char *str);
int		validintsize(char *s);
int		lookfornums(char *s);
int		stack_size(t_stack *stack);
t_stack	*last_stack(t_stack *lst);

/* duplicates.c */
int		has_duplicates(int *numbers, int total_numbers);

/* free_utils.c */
void	free_data(char **p);
void	free_stack(t_stack **stack);

/* swap_move.c */
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

/* rotate_move.c */
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);

/* revrotate_move.c */
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);

/* push_move.c */
int pa(t_stack **a, t_stack **b);
int pb(t_stack **a, t_stack **b);

/* init_stack.c */
void init_stack(t_stack **stack, int *nums, int totalnums);
void test_moves(int *nums, int totalnums);
void print_stack(t_stack *stack);



#endif