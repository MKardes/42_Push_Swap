#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack *tmp;
	t_stack	*sr;

	
}

t_stack	*ft_rb(t_stack *b)
{
	t_stack *tmp;
    t_stack *sr;

    tmp = list_new(b -> content);
    sr = b -> next;
    free(b);
    b = sr;
    b = list_addback(b, tmp);
    return (b);
}

void    ft_rr(t_stack *a, t_stack *b)
{
	t_stack	*c;
	t_stack	*d;

	c = a;
	d = b;
	stack_print(a,b);
	c = ft_ra(c);
	d = ft_rb(d);
	stack_print(c,d);
	a = c;
	b = d;
	stack_print(a, b);
}
