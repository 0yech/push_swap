#include "push_swap.h"

void print_stack(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

void init_stack(t_stack **stack, int *nums, int totalnums)
{
    int     i;
    t_stack *new_node;

    i = totalnums - 1;
    while (i >= 0)
    {
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return ;
        new_node->value = nums[i];
        new_node->next = *stack;
        new_node->prev = NULL;
        if (*stack)
            (*stack)->prev = new_node;
        *stack = new_node;
        i--;
    }
}

void assign_indices(t_stack *a)
{
    t_stack *current;
    t_stack *compare;
	int		index;
	
	current = a;
	while (current)
	{
		index = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}