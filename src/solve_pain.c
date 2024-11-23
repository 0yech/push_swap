/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:18:09 by nrey              #+#    #+#             */
/*   Updated: 2024/11/23 11:24:15 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_solved(t_stack *a, int totalnums)
{
	t_stack	*cpy;
	int		i;

	i = 1;
	cpy = a;
	while (cpy->next != NULL)
	{
		if (cpy->next->index > cpy->index)
			i++;
		cpy = cpy->next;
	}
	if (i != totalnums)
		return (0);
	return (1);
}

int	count_bits(int totalnums)
{
	int	max_bits;

	max_bits = 0;
	while ((totalnums - 1) >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	process_bit(t_stack **a, t_stack **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	solve_pain(t_stack **a, t_stack **b, int totalnums)
{
	int	max_bits;
	int	i;

	max_bits = count_bits(totalnums);
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, i, totalnums);
		i++;
	}
}
//if (is_a_solved(*a, totalnums) == 1)
//ft_printf("Solved\n moves\n");
