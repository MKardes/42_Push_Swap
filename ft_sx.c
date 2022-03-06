#include "push_swap.h"

void    ft_sa(t_stack *a)
{
	t_stack	*tmp;

	tmp = list_new(a -> content);
	a -> content = a -> next -> content;
	a -> next -> content = tmp -> content;
	free(tmp);
}

void    ft_sb(t_stack *b)
{
    t_stack *tmp;

    tmp = list_new(b -> content);
    b -> content = b -> next -> content;
    b -> next -> content = tmp -> content;
    free(tmp);
}

void    ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
}

