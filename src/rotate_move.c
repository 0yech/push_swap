/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:37:00 by nrey              #+#    #+#             */
/*   Updated: 2024/11/23 11:37:06 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*head) < 2)
		return (0);
	first = *head;
	last = last_stack(first);
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	return (1);
}

int	ra(t_stack **a)
{
	if (rotate(a) != 1)
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **b)
{
	if (rotate(b) != 1)
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	if ((stack_size(*a) < 2) || (stack_size(*b) < 2))
		return (0);
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return (1);
}
