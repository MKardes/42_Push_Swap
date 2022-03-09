/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:09 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/09 20:15:03 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int i)
{
	int	tmp;

	tmp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int i)
{
	int	tmp;

	tmp = b -> content;
	b -> content = b -> next -> content;
	b -> next -> content = tmp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 2);
	ft_sb(b, 2);
	write(1, "ss\n", 3);
}
