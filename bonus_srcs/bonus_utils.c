#include "../includes/push_swap.h"

int     execute(char *line, t_stack *a, t_stack *b)
{
    if (strcmp(line, "pa\n") == 0)
        pa(a, b);
    else if (strcmp(line, "pb\n") == 0)
        pb(a, b);
    else if (strcmp(line, "sa\n") == 0)
        sa(a);
    else if (strcmp(line, "sb\n") == 0)
        sb(b);
    else if (strcmp(line, "ra\n") == 0)
        ra(a);
    else if (strcmp(line, "rb\n") == 0)
        rb(b);
    else if (strcmp(line, "rra\n") == 0)
        rra(a);
    else if (strcmp(line, "rrb\n") == 0)
        rrb(b);
    else if (strcmp(line, "rrr\n") == 0)
        rrr(a, b);
    else if (strcmp(line, "rr\n") == 0)
        rr(a, b);
    else if (strcmp(line, "ss\n") == 0)
        ss(a, b);
    else
        return (0);
    return (1);
}
