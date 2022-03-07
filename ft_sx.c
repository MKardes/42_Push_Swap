#include "push_swap.h"

void    ft_sa(t_stack *a, int i)
{
	int	tmp;

	tmp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = tmp;
	if (i == 1)
		write(1, "sa", 2);
}

void    ft_sb(t_stack *b, int i)
{
    	int	tmp;
    
	tmp = b -> content;
    	b -> content = b -> next -> content;
    	b -> next -> content = tmp;
    	if (i == 1)
    		write(1, "sb", 2);
}

void    ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 2);
	ft_sb(b, 2);
	write(1, "ss", 2);
}

