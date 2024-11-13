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

void test_moves(int *nums, int totalnums)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    init_stack(&a, nums, totalnums);
    ft_printf("init_stack output:\n");
    print_stack(a);

    sa(&a);
    ft_printf("after sa:\n");
    print_stack(a);

    ra(&a);
    ft_printf("after ra:\n");
    print_stack(a);

    pb(&a, &b);
    ft_printf("stack a after pb:\n");
    print_stack(a);
	ft_printf("stack b after pb:\n");
	print_stack(b);

	pb(&a, &b);
    ft_printf("stack a after pb:\n");
    print_stack(a);
	ft_printf("stack b after pb:\n");
	print_stack(b);

    free_stack(&a);
    free_stack(&b);
}
