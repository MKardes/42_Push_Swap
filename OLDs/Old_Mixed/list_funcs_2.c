/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:00:39 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/09 20:42:26 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hayirlisi(int *a)
{
	error();
	free(a);
	return (0);
}

t_stack	*get_listlast(t_stack *x)
{
	while (x -> next)
		x = x -> next;
	return (x);
}

t_stack	*get_last2(t_stack *x)
{
	while (x -> next -> next)
		x = x -> next;
	return (x);
}
