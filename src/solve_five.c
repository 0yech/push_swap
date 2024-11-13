#include "push_swap.h"

int     get_small_pos(t_stack *a)
{
    t_stack *current;
    int smallindex;
    int pos;
    int i;

    current = a;
    smallindex = current->index;
    pos = 0;
    i = 0;
    while (current)
    {
        if (current->index < smallindex)
        {
            smallindex = current->index;
            pos = i;
        }
        current = current->next;
        i++;
    }
    return (pos);
}

void    move_on_top(t_stack **a, int pos, int size)
{
    if (pos <= (size / 2))
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        while (pos++ < size)
            rra(a);
    }
}

void    push_smallb(t_stack **a, t_stack **b, int size)
{
    int pos;

    pos = get_small_pos(*a);
    move_on_top(a, pos, size);
    pb(a, b);
}

void    solve_five(t_stack **a, t_stack **b, int totalnums)
{
    if (totalnums == 2)
    {
        sa(a);
        return ;
    }
    push_smallb(a, b, 5);
    if (totalnums == 5)
        push_smallb(a, b, 4);
    solve_three(a);
    if (totalnums == 5)
        pa(a, b);
    pa(a, b);
}