#include "push_swap.h"

void    stack_print(t_stack *a, t_stack *b)
{
    int x = list_size(a);
    int y = list_size(b);
    printf("\n\n-------  -------");
    while (a != NULL && b != NULL)
    {
        if (a -> content >= 0 && a -> content < 10)
            printf("\n|  %d  |  ", a -> content);
        else if (a -> content >= 10 && a -> content < 100)
            printf("\n|  %d |  ", a -> content);
        else if (a -> content >= 100 && a -> content < 1000)
            printf("\n| %d |  ", a -> content);
        else if (a -> content >= 1000 && a -> content < 10000)
            printf("\n| %d|  ", a -> content);
        else
            printf("\n|%d|  ", a -> content);
        if (b -> content >= 0 && b -> content < 10)
            printf("|  %d  |", b -> content);
        else if (b -> content >= 10 && b -> content < 100)
            printf("|  %d |", b -> content);
        else if (b -> content >= 100 && b -> content < 1000)
            printf("| %d |", b -> content);
        else if (b -> content >= 1000 && b -> content < 10000)
            printf("| %d|", b -> content);
        else
            printf("|%d|", b -> content);;
        a = a -> next;
        b = b -> next;
    }
    while (x > y && a)
    {
        if (a -> content >= 0 && a -> content < 10)
            printf("\n|  %d  |  |     |", a -> content);
        else if (a -> content > 10 && a -> content < 100)
            printf("\n|  %d |  |     |", a -> content);
        else if (a -> content >= 100 && a -> content < 1000)
            printf("\n| %d |  |     |", a -> content);
        else if (a -> content >= 1000 && a -> content < 10000)
            printf("\n| %d|  |     |", a -> content);
        else
            printf("\n|%d|  |     |", a -> content);
        a = a -> next;
    }
    while (y > x && b)
    {
        if (b -> content >= 0 && b -> content < 10)
            printf("\n|     |  |  %d  |", b -> content);
        else if (b -> content > 10 && b -> content < 100)
            printf("\n|     |  |  %d |", b -> content);
        else if (b -> content >= 100 && b -> content < 1000)
            printf("\n|     |  | %d |", b -> content);
        else if (b -> content >= 1000 && b -> content < 10000)
            printf("\n|     |  | %d|", b -> content);
        else
            printf("\n|     |  |%d|", b -> content);
        b = b -> next;
    }
    printf("\n-------  -------");
    printf("\nStack A  Stack B\n\n");
}
