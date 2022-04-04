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
        	return (RA);
		return (-1);
	}
	if (a -> content > a_last -> content && b -> content < b_last -> content)
		return (RR);
    else if (b -> content < b_last -> content)
		return (RB);
	if (a -> content > a_last -> content)
        return (RA);
	return (-1);
}

int	is_sx(t_stack *a, t_stack *b)
{
	if (a -> content > a -> next -> content && b -> content < b -> next -> content)
		return (SS);
	if (b -> content < b -> next -> content)
		return (SB);
	if (a -> content > a -> next -> content)
		return (SA);
	return (-1);
}
