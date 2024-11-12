#include "push_swap.h"

static int    swap(t_stack **head)
{
    t_stack *second;
    t_stack *first;

    if (!*head || !(*head)->next)
        return (0);
    first = *head;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *head = second;
    return (1);
}

int    sa(t_stack **a)
{
    if (swap(a) != 1)
        return (0);
    ft_printf("sa\n");
    return (1);
}

int    sb(t_stack **b)
{
    if (swap(b) != 1)
        return (0);
    ft_printf("sb\n");
    return (1);
}

int    ss(t_stack **a, t_stack **b)
{
    if ((stack_size(*a) < 2) || (stack_size(*b) < 2))
        return (0);
    swap(a);
    swap(b);
    ft_printf("ss\n");
    return (1);
}