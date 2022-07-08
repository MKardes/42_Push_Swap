/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partly_sorting_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:15 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 07:55:16 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_continue(t_stack **a, t_stack **b, t_data *data, int *x)
{
	if (data -> mid == 1 && ((*x) == 1))
	{
		if ((*a)-> index == data -> j)
		{
			ft_sa(*a, 1, data);
			data -> big = 2;
		}
		else
		{
			data -> sml = 2;
			ft_ra(a);
		}
	}
	else if ((*x) == 2 && data -> mid == 1)
	{
		if (data -> big == 0)
		{
			ft_sa(*a, 1, data);
			ft_rra(a);
		}
	}
}

static void	triple_check(t_stack **a, t_stack **b, t_data *data, int *x)
{
	if ((*x) == 0 && (*a)-> index == data -> i)
	{
		ft_ra(a);
		data -> sml = 1;
	}
	else if ((*x) == 0 && ((*a)-> index == data -> i + 1))
		data -> mid = 1;
	else if ((*x) == 0 && ((*a)-> index == data -> j))
		data -> big = 1;
	else if (data -> sml == 1 && (*x) == 2)
	{
		if ((*a)-> index == data -> j)
			ft_sa(*a, 1, data);
		ft_rra(a);
	}
	else if (data -> big == 1 && (*x) == 2 && (*a)-> index == data -> j - 1)
		ft_sa(*a, 1, data);
	else
		check_continue(a, b, data, x);
	(*x)++;
}

static void	first(t_stack **a, t_stack **b, t_data *data, int *k)
{
	ft_rn(a, b, (*k), 'b');
	ft_pa(a, b, data);
	(*k) = -1;
	data -> last_part--;
}

static void	second(t_stack **a, t_stack **b, t_data *data, int *k)
{
	ft_rrn(a, b, (*k) + 1, 'b');
	ft_pa(a, b, data);
	(*k) = -1;
	data -> last_part--;
}

void	part_2(t_stack **a, t_stack **b, t_data *data)
{
	int	x;
	int	k;

	x = 0;
	k = 0;
	while (k < data -> b_cnt / 2)
	{
		if (index_check(*b, k, data -> i, data -> j))
		{
			first(a, b, data, &k);
			triple_check(a, b, data, &x);
		}
		else if (index_check(*b, data -> b_cnt - k - 1, data -> i, data -> j))
		{
			second(a, b, data, &k);
			triple_check(a, b, data, &x);
		}
		if (x == 3)
			triple_clean(data, &k, &x);
		k++;
	}
	last_push(a, b, data);
}
