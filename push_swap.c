/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/04/04 17:23:59 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_finder(t_stack *a)
{
	int	min;

	min = a -> content;
	while (a -> next)
	{
		if (a -> content < min)
			min = a -> content;
		a = a -> next;
	}
	if (a -> content < min)
			min = a -> content;
	return (min);
}

int	ra_rra_choice(int min, t_stack *a, t_data *data)
{
	int	i;

	i = 1;
	if (a -> content == min)
		return (2);
	while (a -> next && a -> content != min)
	{
		a = a -> next;
		i++;
	}
	if ((data -> a_cnt - i) >= data -> a_cnt / 2)
		return (RA);
	return (RRA);
}

void	get_it(t_stack **a, t_stack **b, int format, int min, t_data *data)
{
	if (format == 2)
		ft_pb(a, b, data);
	else if (format == RA)
	{
		while ((*a) -> content != min)
			ft_ra(a, 1, data);
		ft_pb(a, b, data);
	}
	else
	{
		while ((*a) -> content != min)
			ft_rra(a, 1, data);
		ft_pb(a, b, data);
	}
}

void	begin(t_stack **a, t_stack **b, t_data *data)
{
	int	min;
	int	format;
	
	while ((*a) -> next)
	{
		min = min_finder(*a);
		format = ra_rra_choice(min, *a, data);
		get_it(a, b, format, min, data);
	}
	while (*b)
		ft_pa(a, b, data);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;

	b = NULL;
	a = NULL;
	a = ft_atol(a, av, &data);
	data.count += 1;
    data.a_cnt = data.count;
    data.b_cnt = 0;
	begin(&a, &b, &data);
	return (0);
}
