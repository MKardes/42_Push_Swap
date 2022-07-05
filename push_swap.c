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

void	begin(t_stack **a, t_stack **b, t_data *data)
{
	int i;
	t_stack *tmp;

	i = 0;
	while (i < 3)
	{
		tmp = get_listlast(*a);
		while ((*a) != tmp)
		{
			printf("indis: %d\n", (*a) -> index);
			if (((*a) -> index >> i & 1) != 1)
			{
				printf("%d,",(*a) -> content);
				ft_pb(a, b, data);
			}
			else
				ft_ra(a, 1, data);
		}
		if (((*a) -> index >> i | 0) == 0)
			ft_pb(a, b, data);
		else
			ft_ra(a, 1, data);
		while ((*b) && (*b) -> next)
		{
			ft_pa(&tmp, b, data);
			*b = (*b) -> next;
		}
		i++;
	}
}

void int_put(int *a)
{
	int i = 0;

	while (i < 10)
	{
		printf("%d, ",a[i]);
		i++;
	}
	printf("\n");
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
	array_sort(&data.s, data.count);
	stack_indisle(&a, data);
	stack_print(a, b, data);
	begin(&a, &b, &data);
	stack_print(a, b, data);
	return (0);
}
