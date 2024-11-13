#include "push_swap.h"

void	solve_three(t_stack **a)
{
	int	first = (*a)->index;
	int second = (*a)->next->index;
	int third = (*a)->next->next->index;

	if (first > second && second < third && first < third)
		sa(a); // E
	else if (first > second && second > third)
	{
		sa(a); // F
		rra(a);
	}
	else if (first > second && second < third)
		ra(a); // G
	else if (first < second && second > third && first < third)
	{
		sa(a); // H
		ra(a);
	}
	else if (first < second && second > third)
		rra(a); // I
}

/*

	E) first is misplaced with second.
	F) stack is reversed.
	G) the first node is the biggest.
	H) the second node is the biggest.
	I) last node is the biggest.

*/