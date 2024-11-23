/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:47:02 by nrey              #+#    #+#             */
/*   Updated: 2024/11/23 11:47:30 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	douane(int argc, char **argv, int **nums, int *totalnums)
{
	if (argc < 2)
		return (0);
	if (!init_nums(argv, nums, totalnums) || !valid_args(argc, argv))
	{
		ft_printf("Error\n");
		free(*nums);
		return (0);
	}
	if (is_sorted(*nums, *totalnums))
	{
		free(*nums);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*nums;
	int		totalnums;

	a = NULL;
	b = NULL;
	nums = NULL;
	totalnums = 0;
	if (!douane(argc, argv, &nums, &totalnums))
		return (1);
	init_stack(&a, nums, totalnums);
	assign_indices(a);
	if (totalnums == 3)
		solve_three(&a);
	else if (totalnums == 5 || totalnums == 4 || totalnums == 2)
		solve_five(&a, &b, totalnums);
	else if (totalnums > 5)
		solve_pain(&a, &b, totalnums);
	free_stack(&a);
	free_stack(&b);
	free(nums);
	return (0);
}

// REMINDERS

// Dereference when willing to get values from a list directly.
// Example in push_move : "(*src)->next" and not "*src->next"
// Because the -> operator has priority over the *.
// This must be done when working with the list itself.
// Like head, src or dst.
// **src does not contain a "next" field, as it's the list itself.
// Dereferencing src let's us access it's node and therefore, fields.