/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:37:42 by nrey              #+#    #+#             */
/*   Updated: 2024/11/23 11:38:04 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverserotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack_size(*head) < 2)
		return (0);
	last = last_stack(*head);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
	return (1);
}

int	rra(t_stack **a)
{
	if (reverserotate(a) == -1)
		return (0);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **b)
{
	if (reverserotate(b) == -1)
		return (0);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	if ((stack_size(*a) < 2) || (stack_size(*b) < 2))
		return (0);
	reverserotate(a);
	reverserotate(b);
	ft_printf("rrr\n");
	return (1);
}
