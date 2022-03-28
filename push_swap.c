/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/28 23:26:36 by mkardes          ###   ########.fr       */
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
*/

void	rr_check(t_stack **a, t_stack **b)
{
	int rx;

    rx = is_rx(*a, *b);
    stack_print(*a,*b);
    if (rx == ra)
        ft_ra(a, 1);
    else if (rx == rb)
        ft_rb(b, 1);
    else if (rx == rr)
        ft_rr(a, b);
	
}

void	ss_check(t_stack **a, t_stack **b)
{
	int	sx;

	sx = is_sx(*a, *b);
	stack_print(*a, *b);
    if (sx == sa)
        ft_sa(*a, 1);
    else if (sx == rb)
        ft_sb(*b, 1);
    else if (sx == ss)
        ft_ss(*a, *b);
}

void	first_algorithm(t_stack **a, t_stack **b)
{
	int	i = 0;
	stack_print(*a, *b);
	while ((*a) -> next)
	{
		printf("1\n");
		rr_check(a, b);
		printf("2\n");
		ss_check(a, b);
		printf("3\n");
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
