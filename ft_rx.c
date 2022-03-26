/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:41 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/26 15:36:20 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	last = get_listlast(*a);
	last -> next = first;
	*a = first -> next;
	first -> next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*last;

	first = *b;
	last = get_listlast(*b);
	last -> next = first;
	*b = first -> next;
	first -> next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 2);
	ft_rb(b, 2);
	write(1, "rr\n", 3);
}
