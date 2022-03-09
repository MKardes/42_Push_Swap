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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*s;
	int		i;

	b = NULL;
	a = NULL;
	a = ft_atol(a, av, s);
	free(s);
	i = 0;
	while (i++ < 5)
		ft_pb(&a, &b);
	if (!a)
		return (0);
	stack_print(a, b);
	ft_pa(&a, &b);
	stack_print(a, b);
	return (0);
}
