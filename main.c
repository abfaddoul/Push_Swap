#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    if (ac < 2)
        return (0);

    build_stack_a(&a, ac, av);
    check_duplicates(&a);
    turk_sort(&a, &b);
    return (0);
}
