/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:00:39 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/06 15:51:11 by mkardes          ###   ########.fr       */
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

void	array_sort(int **a, int h)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < h - 1)
	{
		j = i + 1;
		while (j < h)
		{
			if (a[0][i] > a[0][j])
			{
				tmp = a[0][i];
				a[0][i] = a[0][j];
				a[0][j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	stack_indisle(t_stack **a, t_data data)
{
	t_stack *tmp;
	int		i;

	i = 0;
	while (i < data.count)
	{
		tmp = *a;
		while (tmp != NULL)
		{
			if (tmp -> content == data.s[i])
				tmp -> index = i;			
			tmp = tmp -> next;
		}
		i++;
	}
}
