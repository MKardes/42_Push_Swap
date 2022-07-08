/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partly_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:28:36 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 07:45:09 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_check(t_stack *a, int k, int i, int j)
{
	int	y;

	y = 0;
	while (y < k)
	{
		a = a -> next;
		y++;
	}
	if (a -> index >= i && a -> index <= j)
		return (1);
	return (0);
}

void	continue_pushing(t_stack **a, t_stack **b, t_data *data)
{
	data -> last_part = data -> a_cnt - 3;
	while (data -> a_cnt != 3)
	{
		if ((*a)-> index == data -> count - 1 || (*a)-> index
			== data -> count - 2 || (*a)-> index == data -> count - 3)
			ft_ra(a);
		else
			ft_pb(a, b, data);
	}
	algorithm_3(a, data);
}

void	missing_while(t_stack **a, t_stack **b, t_data *data, int *k)
{
	int	g;

	while ((*k) < data -> a_cnt / 2)
	{
		g = 0;
		if (index_check(*a, *k, data -> i, data -> j))
		{
			while (g++ < (*k))
				ft_ra(a);
			ft_pb(a, b, data);
			*k = 0;
		}
		else if (index_check(*a, data -> a_cnt - (*k)
				- 1, data -> i, data -> j))
		{
			while (g++ < (*k) + 1)
				ft_rra(a);
			*k = 0;
			ft_pb(a, b, data);
		}
		(*k)++;
	}
}

void	partly_sorting(t_stack **a, t_stack **b, t_data *data)
{
	int	k;

	while (data -> a_cnt >= BUFF)
	{
		data -> j = data -> i + BUFF - 1;
		k = 0;
		missing_while(a, b, data, &k);
		data -> i += BUFF;
	}
	continue_pushing(a, b, data);
	data -> i = data -> count - 6;
	data -> j = data -> count - 4;
	part_2(a, b, data);
}

void	algorithm_3(t_stack **a, t_data *data)
{
	if (is_sorted(*a))
		return ;
	if ((*a)-> index < (*a)-> next -> index && (*a)->index
		< (*a)-> next-> next -> index)
	{
		ft_rra(a);
		ft_sa(*a, 1, data);
	}
	else if ((*a)->index < (*a)-> next -> index && (*a)-> index
		> (*a)-> next -> next -> index)
		ft_rra(a);
	else if ((*a)-> index < (*a)-> next -> next -> index)
		ft_sa(*a, 1, data);
	else if ((*a)-> next -> index > (*a)-> next -> next -> index)
	{
		ft_sa(*a, 1, data);
		ft_rra(a);
	}
	else
		ft_ra(a);
}
