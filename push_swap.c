/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 07:55:53 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_5(t_stack **stack, t_stack **stack_b, t_data *data)
{
	int	size;
	int	index;
	int	i;

	i = 0;
	size = data -> count;
	while (data -> a_cnt > 3)
	{
		if ((*stack)-> index < 2)
			ft_pb(stack, stack_b, data);
		else
			ft_ra(stack);
	}
	algorithm_3(stack, data);
	ft_pan(stack, stack_b, data, 2);
}

int	is_sorted(t_stack *a)
{
	while (a -> next)
	{
		if (a -> content > a -> next -> content)
			return (0);
		a = a -> next;
	}
	return (1);
}

void	begin_radix(t_stack **a, t_stack **b, t_data *data)
{
	int	i;
	int	j;
	int	a_cnt;

	i = 0;
	while (!is_sorted(*a))
	{
		a_cnt = data -> a_cnt;
		j = 0;
		while (j < a_cnt)
		{
			if (((*a)-> index >> i & 1) != 1)
				ft_pb(a, b, data);
			else
				ft_ra(a);
			j++;
		}
		while (*b)
			ft_pa(a, b, data);
		i++;
	}
}

void	begin(t_stack **a, t_stack **b, t_data *data)
{
	int	x;

	if (is_sorted(*a))
		return ;
	if (data -> a_cnt == 3)
	{
		algorithm_3(a, data);
		return ;
	}
	if (data -> a_cnt == 5)
		algorithm_5(a, b, data);
	else if (data -> count <= 100)
	{
		triple_clean(data, &x, &x);
		data -> i = 0;
		partly_sorting(a, b, data);
	}
	else if (data -> count > 100)
		begin_radix(a, b, data);
	free(data -> s);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;

	if (ac > 1)
	{
		b = NULL;
		a = NULL;
		a = ft_atol(a, av, &data);
		if (!a)
			return (0);
		data.count += 1;
		data.a_cnt = data.count;
		data.b_cnt = 0;
		array_sort(&data.s, data.count);
		stack_indisle(&a, data);
		begin(&a, &b, &data);
	}
	return (0);
}
