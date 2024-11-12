#include "push_swap.h"

int push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (stack_size(*src) == 0)
        return (0);
    if (!src)
        return (0);
    tmp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    tmp->next = *dst;
    if (*dst)
        (*dst)->prev = tmp;
    *dst = tmp;
    (*dst)->prev = NULL;
    return (1);
}

int pa(t_stack **a, t_stack **b)
{
    if (push(b, a) != 1)
        return (0);
    ft_printf("pa\n");
    return (1);
}

int pb(t_stack **a, t_stack **b)
{
    if (push(a, b) != 1)
        return (0);
    ft_printf("pb\n");
    return (1);
}