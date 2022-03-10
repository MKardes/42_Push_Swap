/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/09 20:24:56 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *a)
{
	while (a -> next)
	{
		if (a -> next -> content < a -> content)
			return (0);
		a = a -> next;
	}
	return (1);
}

int	checker(t_stack *a)
{
	int	x;
	int	y;
	int	z;
	int	dif;
	int	div;

	x = a -> content;
	y = a -> next -> content;
	a = get_listlast(a);
	z = a -> content;
	dif = x - y;
	div = x - z;
	if (dif < div)
	{
		if (dif - div == -1)
			return (0);
		else
			return (1);
	}
	else
		return(2);
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
	free(s);
	while (!check_sort(a))
	{
		if (checker(a) == 0)
			ft_sa(a, 1);
		else if (checker(a) == 1)
			ft_rra(&a, 1);
		else
			ft_ra(&a, 1);

	}
	i = 0;
	while (i++ < 1)
		ft_pb(&a, &b);
	if (!a)
		return (0);
	ft_pa(&a, &b);
	stack_print(a, b);
	return (0);
}
