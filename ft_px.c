/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:59:03 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/08 07:37:04 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (!*b)
		return ;
	tmp = *b;
	tmp_b = *b;
	*b = tmp_b -> next;
	tmp -> next = *a;
	*a = tmp;
	(*data).a_cnt++;
	(*data).b_cnt--;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp_a;

	if (!*a)
		return ;
	tmp = *a;
	tmp_a = *a;
	*a = tmp_a -> next;
	tmp -> next = *b;
	*b = tmp;
	(*data).a_cnt--;
	(*data).b_cnt++;
	write(1, "pb\n", 3);
}

void	ft_pan(t_stack **a, t_stack **b, t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_pa(a, b, data);
		i++;
	}
}

void	ft_pbn(t_stack **a, t_stack **b, t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_pb(a, b, data);
		i++;
	}
}
