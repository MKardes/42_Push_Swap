/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/31 20:20:25 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_check(t_stack **a, t_stack **b, t_data *data)
{
	int rx;

    rx = is_rx(*a, *b);
    if (rx == ra)
        ft_ra(a, 1, data);
    else if (rx == rb)
        ft_rb(b, 1, data);
	else if (rx == rr)
        ft_rr(a, b, data);
}

void	ss_check(t_stack **a, t_stack **b, t_data *data)
{
	int	sx;

	if (!*b)
	{
		if ((*a) -> content > (*a) -> next -> content)
			ft_sa(*a, 1, data);
		return ;
	}
	if (!((*a) -> next) || !((*b) -> next))
	{
		if (!((*b) -> next) && (*a) -> content > (*a) -> next -> content)
			ft_sa(*a, 1, data);
		else if (!((*a) -> next) && (*b) -> content < (*b) -> next -> content)
			ft_sb(*b, 1, data);
		return ;
	}
	sx = is_sx(*a, *b);
    if (sx == sa)
        ft_sa(*a, 1, data);
	else if (sx == sb)
        ft_sb(*b, 1, data);
	else if (sx == ss)
        ft_ss(*a, *b, data);
}

int	a_check(t_stack *a)
{
	while (a -> next)
	{
		if (a -> content > a -> next -> content)
			return (0);
		a = a -> next;
	}
	return (1);
}

int b_check(t_stack *b)
{
	if (!b)
		return (1);
    while (b -> next)
    {
        if (b -> content < b -> next -> content)
            return (0);
        b = b -> next;
    }
    return (1);
}

int	all_check(t_stack **a, t_stack **b)
{
	if (a_check(*a) && b_check(*b))
	{
		if ((*a) -> content < (*b) -> content)
			return (1);
	}
	return (0);
}

void	move_to_b(t_stack **a, t_stack **b, t_data *data)
{
	while ((*data).a_cnt > (*data).a_rst)
	{
		rr_check(a, b, data);
		ss_check(a, b, data);
		ft_pb(a,b, data);
		(*data).a_cnt--;
		(*data).b_cnt++;
	}
}

int	move_a_check(t_stack **a, t_stack **b, t_data *data)
{
	if (a_check(*a))
	{
		if ((*a) -> content > (*b) -> content && b_check(*b))
		{
			return (1);
		}
	}
	return (0);
}

void	move_to_a(t_stack **a, t_stack **b, t_data *data)
{
	while ((*data).b_cnt > (*data).b_rst)
	{
		rr_check(a, b, data);
		ss_check(a, b, data);
		ft_pa(a, b, data);
		(*data).b_cnt--;
		(*data).a_cnt++;
	}
}

void	start(t_stack **a, t_stack **b, t_data *data)
{
	(*data).count += 1;
    (*data).a_cnt = (*data).count;
    (*data).b_cnt = 0;
	//while (!(all_check(a, b, &(*data).gecici)))
	int	i = 0;
	while (i < 14)
	{
		move_to_b(a, b, data);
		//stack_print(*a, *b, *data);
		move_to_a(a, b, data);
		(*data).a_rst += 2;
		(*data).b_rst += 2;
		//stack_print(*a, *b, *data);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;
	data.a_rst = 2;
	data.b_rst = 2;
	int		i;

	b = NULL;
	a = NULL;
	a = ft_atol(a, av, &data);
	start(&a, &b, &data);
	//while (!(all_check(&a, &b, &gecici))
	stack_print(a, b, data);
	while (data.steps)
	{
		printf("%s",data.steps -> content);
		data.steps = data.steps -> next;
	}
	return (0);
}
