/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/04/04 15:05:37 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **a, t_stack **b, t_data *data)
{
	while ((*data).a_cnt > (*data).a_rst)
	{
		rr_check(a, b, data);
		ss_check(a, b, data);
		ft_pb(a,b, data);
		(*data).a_cnt--;
		(*data).b_cnt++;
	}
}

int	move_a_check(t_stack **a, t_stack **b, t_data *data)
{
	if (a_check(*a))
	{
		if ((*a) -> content > (*b) -> content && b_check(*b))
		{
			return (1);
		}
	}
	return (0);
}

void	move_to_a(t_stack **a, t_stack **b, t_data *data)
{
	while ((*data).b_cnt > (*data).b_rst)
	{
		rr_check(a, b, data);
		ss_check(a, b, data);
		ft_pa(a, b, data);
		(*data).b_cnt--;
		(*data).a_cnt++;
	}
}

void	begin(&a)

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;
	data.a_rst = 2;
	data.b_rst = 2;
	data.steps = NULL;
	int		i;

	b = NULL;
	a = NULL;
	a = ft_atol(a, av, &data);
	begin(&a, &b, &data)
	return (0);
}
