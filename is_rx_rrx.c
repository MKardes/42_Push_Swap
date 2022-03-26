#include "push_swap.h"

int is_rx(t_stack *a, t_stack *b)
{
	t_stack *a_last;
    t_stack *b_last;
	int		c;

	c = 0;
    a_last = list_last(a);
    b_last = list_last(b);
	if (a -> content > a_last -> content)
		c += 1;
	if (b != NULL)
    {
        if (b -> content < b_last -> content)
		{
			if (c == 1)
				return (rr);
			else
				return (rb);
		}
	}
	return (ra);
}

int is_rra(t_stack *a)
{
	t_stack *a_last;
    
	a_last = list_last(a);
	if (a -> content < a_last -> content)
		return (1);
	return (0);
}
