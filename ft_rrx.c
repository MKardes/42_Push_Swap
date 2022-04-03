/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:17 by mkardes           #+#    #+#             */
/*   Updated: 2022/04/03 21:25:29 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a, int i, t_data *data)
{
	t_stack	*last2;
	t_stack	*tmp;
	t_stack	*first;

	last2 = get_last2(*a);
	tmp = last2 -> next;
	tmp -> next = *a;
	last2 -> next = NULL;
	*a = tmp;
	if (i == 1)
		steps("rra\n", data, -1);
		//write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int i, t_data *data)
{
	t_stack	*last2;
	t_stack	*tmp;
	t_stack	*first;

	last2 = get_last2(*b);
	tmp = last2 -> next;
	tmp -> next = *b;
	last2 -> next = NULL;
	*b = tmp;
	if (i == 1)
		steps("rrb\n", data, -1);
		//write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, t_data *data)
{
	ft_rra(a, 2, data);
	ft_rrb(b, 2, data);
	steps("rrr\n", data, -1);
	//write(1, "rrr\n", 4);
}
