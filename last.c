/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 08:59:43 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 13:37:32 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_3(t_stack **a, t_data *data)
{
	if (is_sorted(*a))
		return ;
	if ((*a)-> index < (*a)-> next -> index && (*a)->index
		< (*a)-> next-> next -> index)
	{
		ft_rra(a);
		ft_sa(*a);
	}
	else if ((*a)->index < (*a)-> next -> index && (*a)-> index
		> (*a)-> next -> next -> index)
		ft_rra(a);
	else if ((*a)-> index < (*a)-> next -> next -> index)
		ft_sa(*a);
	else if ((*a)-> next -> index > (*a)-> next -> next -> index)
	{
		ft_sa(*a);
		ft_rra(a);
	}
	else
		ft_ra(a);
}
