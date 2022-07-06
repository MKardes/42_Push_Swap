/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partly_sorting_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:15 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/06 17:33:57 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_2(t_stack **a, t_stack **b, t_data *data)
{
	int	x;
	int	k;
	int	g;

	x = data -> count / BUFF;
	k = 0;
	while (data -> last_part > 0)
	{
		while ()
		{
		g = 0;
        if (index_check(*b, k, data -> i, data -> j))
        {
            while (g++ < k)
                ft_rb(b, 1, data);
//          printf("\ntop(%d) i: %d\n", (*a) -> content, (*a) -> index);
            ft_pa(a, b, data);
			data -> last_part--;
            k = 0;
        }
        else if (index_check(*b, data -> a_cnt - k- 1, data -> i, data -> j))
        {
            while (g++ < k + 1)
                ft_rrb(b, 1, data);
            k = 0;
//      printf("\nbot(%d) i: %d\n", (*a) -> content, (*a) -> index);
        ft_pa(a, b, data);
		data -> last_part--;
        }
        k++;
		}
//		if (index_check(*b, -12, data -> i, data -> j)
	}
	/*while (x > 0)
	{

		x--;
	}*/
}
