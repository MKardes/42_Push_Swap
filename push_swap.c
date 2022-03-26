/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/26 18:31:44 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    int rx;

    rx = is_rx(*a, *b);
    stack_print(*a,*b);
    if (rx == ra)
        ft_ra(a, 1);
    else if (rx == rb)
        ft_rb(b, 1);
    else if (rx == rr)
        ft_rr(a, b);
    if (is_rra(*a))
        ft_rra(a, 1);
*/

void	rr_check(t_stack **a, t_stack **b)
{
	t_stack *a_last;
	t_stack *b_last;

	a_last = list_last(*a);
	b_last = list_last(*b);
	stack_print(*a,*b);
	//printf("%d -a-last-> %d\n", (*a) -> content, a_last -> content);
	//if (b_last)
	//	printf("%d -b_last-> %d\n", (*b) -> content, b_last -> content);
	if ((*a) -> content > a_last -> content)
	{
		ft_ra(a, 1);
	}
	//if ((*a) -> content < a_last -> content)
	//	ft_rra(a, 1);
	if ((*b) != NULL)
	{
		if ((*b) -> content < b_last -> content)
			ft_rb(b, 1);
	}
}

void	first_algorithm(t_stack **a, t_stack **b)
{
	int	i = 0;
	stack_print(*a, *b);
	while ((*a) -> next)
	{
		rr_check(a, b);
		if (((*a) -> content < (*a) -> next -> content))
			ft_pb(a,b);
		else if (((*a) -> content > (*a) -> next -> content))
			ft_sa(*a,1);
		//printf("error\n");
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*s;
	int		i;

	b = NULL;
	a = NULL;
	a = ft_atol(a, av, &s);
	first_algorithm(&a,&b);
	stack_print(a, b);
	return (0);
}
