#include "push_swap.h"

int		is_a_solved(t_stack *a, int totalnums)
{
	// returns 1 if the stack is solved !
	t_stack *cpy;
	int i;

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

void    solve_pain(t_stack **a, t_stack **b, int totalnums)
{
	int c;
	int aled;

	c = totalnums;
	aled = 0;
	while (c)
	{
		aled += pain_on_top(a, get_small_pos(*a), stack_size(*a));
		pb(a, b);
		aled++;
		c--;
		
	}
	while (c != totalnums)
	{
		pa(a, b);
		c++;
		aled++;
	}
/*
	int n;
	t_stack *lasta;
	t_stack *lastb;
	int c = 0;

	n = totalnums / 2;
	while (n)
	{
		move_on_top(a, get_small_pos(*a), stack_size(*a));
		pb(a, b);
		c++;
		n--;
	}
	//is_a_solved(*a, totalnums) == 0
	while (is_a_solved(*a, totalnums) == 0)
    {
		lasta = last_stack(*a);
		lastb = last_stack(*b);
		if (*a && (*a)->next && (*a)->index > (*a)->next->index)
		{
			sa(a);
			c++;
		}
		else if (*b && (*b)->next && (*b)->index < (*b)->next->index)
		{
			sb(b);
			c++;
		}
		else if (*b && (*a) && (*b)->index == ((*a)->index - 1))
		{
			pa(a, b);
			c++;
		}
		else if (*a && (*b) && (*a)->index == ((*b)->index + 1))
		{
			pb(a, b);
			c++;
			sb(b);
			c++;
		}
		else if (lasta && lasta->prev && lasta->index < lasta->prev->index)
		{
			rra(a);
			c++;
			rra(a);
			c++;
			sa(a);
			c++;
			ra(a);
			c++;
			ra(a);
			c++;
		}
		else if (lastb && lastb->prev && lastb->index > lastb->prev->index)
		{
			rrb(b);
			c++;
			rrb(b);
			c++;
			sb(b);
			c++;
			rb(b);
			c++;
			rb(b);
			c++;
		}
		else
		{
			move_on_top(a, get_small_pos(*a), stack_size(*a));
			pb(a, b);
		}
	}
*/
	if (is_a_solved(*a, totalnums) == 1)
	ft_printf("Solved\n %d moves\n", aled);
}