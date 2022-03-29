#include "push_swap.h"

int is_rx(t_stack *a, t_stack *b)
{
	t_stack *a_last;
    t_stack *b_last;
	int		c;

	c = 0;
    a_last = list_last(a);
    b_last = list_last(b);
	if (!b)
	{
		if (a -> content > a_last -> content)
        	return (ra);
		return (4);
	}
	if (a -> content > a_last -> content && b -> content < b_last -> content)
		return (rr);
    else if (b -> content < b_last -> content)
		return (rb);
	if (a -> content > a_last -> content)
        return (ra);
	return (4);
}

int	is_sx(t_stack *a, t_stack *b)
{
	if (a -> content > a -> next -> content && b -> content < b -> next -> content)
		return (ss);
	if (b -> content < b -> next -> content)
		return (sb);
	if (a -> content > a -> next -> content)
		return (sa);
	return (4);
}
