/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/06 16:13:48 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *a)
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
	int i;
	int	j;
	int	a_cnt;

	i = 0;
	while (!is_sorted(*a))
	{
		a_cnt = data -> a_cnt;
		j = 0;
		while (j < a_cnt)
		{
			if (((*a) -> index >> i & 1) != 1)
				ft_pb(a, b, data);
			else
				ft_ra(a, 1, data);
			j++;
		}
		while (*b)
			ft_pa(a, b, data);
		i++;
	}
}

int rev_sort_triple_check(t_stack **x, t_data *data)
{
	t_stack *a;

	a = *x;
	if ((*data).a_cnt != 3)
		return (0);
	while (a -> next)
	{
		if (a -> content < a -> next -> content)
			return (0);
		a = a -> next;
	}
	ft_ra(x, 1, data);
	ft_sa(*x, 1, data);
	return (1);
}

void	begin(t_stack **a, t_stack **b, t_data *data)
{
	if (data -> a_cnt == 3)
    {
        algorithm_3(a, data);
        return;
    }
	if (is_sorted(*a))
		return ;
	if (rev_sort_triple_check(a, data))
		return ;
	if (data -> count <= 100)
	{
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
		data.count += 1;
    	data.a_cnt = data.count;
    	data.b_cnt = 0;
		array_sort(&data.s, data.count);
		stack_indisle(&a, data);
	//	stack_print(a, b, data);
		begin(&a, &b, &data);
	//	stack_print(a, b, data);
	}
	return (0);
}
