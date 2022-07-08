/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:58:57 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 07:46:21 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_push(t_stack **a, t_stack **b, t_data *data)
{
	if (data -> b_cnt == 0)
		return ;
	if (data -> b_cnt == 2 && (*b)-> index > (*b)-> next -> index)
		ft_sb(*a, 1, data);
	ft_pa(a, b, data);
}

void	triple_clean(t_data *data, int *k, int *x)
{
	(*x) = 0;
	(*k) = -1;
	data -> i -= 3;
	data -> j -= 3;
	data -> sml = 0;
	data -> mid = 0;
	data -> big = 0;
}
