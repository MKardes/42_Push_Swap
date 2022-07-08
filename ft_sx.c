/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:09 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 13:05:45 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int	tmp;

	tmp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b)
{
	int	tmp;

	tmp = b -> content;
	b -> content = b -> next -> content;
	b -> next -> content = tmp;
	write(1, "sb\n", 3);
}
