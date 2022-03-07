#include "push_swap.h"

void	ft_ra(t_stack **a, int i)
{
	t_stack *first;
	t_stack	*last;

	first = *a;
	last = get_listlast(*a);
	last -> next = first;
	*a = first -> next;
	first -> next = NULL;
	if (i == 1)
		write(1, "ra", 2);
}

void    ft_rb(t_stack **b, int i)
{
	t_stack *first;
	t_stack *last;

	first = *b;
	last = get_listlast(*b);
	last -> next = first;
	*b = first -> next;
	first -> next = NULL;
	if (i == 1)
		write(1, "ra", 2);
}

void    ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 2);
	ft_rb(b, 2);
	write(1, "rr", 2);
}
