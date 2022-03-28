/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/29 00:20:20 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_check(t_stack **a, t_stack **b, int *gecici)
{
	int rx;

    rx = is_rx(*a, *b);
    if (rx == ra)
	{
        ft_ra(a, 1);
		gecici[0]++;
	}
    else if (rx == rb)
	{
        ft_rb(b, 1);
		gecici[0]++;
	}
	else if (rx == rr)
	{
        ft_rr(a, b);
		gecici[0]++;
	}
}

void	ss_check(t_stack **a, t_stack **b, int *gecici)
{
	int	sx;

	if (!*b)
	{
		if ((*a) -> content > (*a) -> next -> content)
		{
			ft_sa(*a, 1);
			gecici[0]++;
		}
		return ;
	}
	if (!((*a) -> next) || !((*b) -> next))
	{
		if (!((*b) -> next) && (*a) -> content > (*a) -> next -> content)
		{
			ft_sa(*a, 1);
			(*gecici)++;
		}
		else if (!((*a) -> next) && (*b) -> content < (*b) -> next -> content)
		{
			ft_sb(*b, 1);
			(*gecici)++;
		}
		return ;
	}
	sx = is_sx(*a, *b);
    if (sx == sa)
	{
        ft_sa(*a, 1);
		(*gecici)++;
	}
	else if (sx == sb)
	{
        ft_sb(*b, 1);
		(*gecici)++;
	}
	else if (sx == ss)
	{
        ft_ss(*a, *b);
		(*gecici)++;
	}
}

int sort_check(t_stack **a, t_stack **b, int *gecici)
{

}

void	first_algorithm(t_stack **a, t_stack **b, int *gecici)
{
	int	i = 0;
	stack_print(*a, *b);
	if (sort_check(a, b, gecici))
		return ;
	while ((*a) -> next)
	{
		rr_check(a, b, gecici);
		ss_check(a, b, gecici);
		if (((*a) -> content < (*a) -> next -> content))
		{
			ft_pb(a,b);
			(*gecici)++;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		gecici = 0;
	int		*s;
	int		i;

	b = NULL;
	a = NULL;
	a = ft_atol(a, av, &s);
	first_algorithm(&a,&b, &gecici);
	stack_print(a, b);
	printf("*****%d*****",gecici);
	return (0);
}
