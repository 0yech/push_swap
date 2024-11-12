#include "push_swap.h"

void	free_data(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i++]);
	}
	free(p);
}

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}