/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:17 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/07 19:54:12 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*last2;
	t_stack	*tmp;
	t_stack	*first;

	last2 = get_last2(*a);
	tmp = last2 -> next;
	tmp -> next = *a;
	last2 -> next = NULL;
	*a = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*last2;
	t_stack	*tmp;
	t_stack	*first;

	last2 = get_last2(*b);
	tmp = last2 -> next;
	tmp -> next = *b;
	last2 -> next = NULL;
	*b = tmp;
	write(1, "rrb\n", 4);
}
