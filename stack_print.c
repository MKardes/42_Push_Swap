/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:15:27 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/29 12:33:33 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_print(t_stack *a, t_stack *b, t_data data)
{
	int	x;
	int	y;

	x = list_size(a);
	y = list_size(b);
	printf("\n\n-------  -------");
	while (a != NULL && b != NULL)
	{
		if (a -> content >= 0 && a -> content < 10)
			printf("\n|  %d  |  ", a -> content);
		else if ((a -> content >= 10 && a -> content < 100)
			|| (a -> content < 0 && a -> content > -10))
			printf("\n|  %d |  ", a -> content);
		else if ((a -> content >= 100 && a -> content < 1000)
			|| (a -> content <= -10 && a -> content > -100))
			printf("\n| %d |  ", a -> content);
		else if ((a -> content >= 1000 && a -> content < 10000)
			|| (a -> content <= -100 && a -> content > -1000))
			printf("\n| %d|  ", a -> content);
		else
			printf("\n|%d|  ", a -> content);
		if (b -> content >= 0 && b -> content < 10)
			printf("|  %d  |", b -> content);
		else if ((b -> content >= 10 && b -> content < 100)
			|| (b -> content < 0 && b -> content > -10))
			printf("|  %d |", b -> content);
		else if ((b -> content >= 100 && b -> content < 1000)
			|| (b -> content <= -10 && b -> content > -100))
			printf("| %d |", b -> content);
		else if ((b -> content >= 1000 && b -> content < 10000)
			|| (b -> content <= -100 && b -> content > -1000))
			printf("| %d|", b -> content);
		else
			printf("|%d|", b -> content);
		a = a -> next;
		b = b -> next;
	}
	while (x > y && a)
	{
		if (a -> content >= 0 && a -> content < 10)
			printf("\n|  %d  |  |     |", a -> content);
		else if ((a -> content >= 10 && a -> content < 100)
			|| (a -> content < 0 && a -> content > -10))
			printf("\n|  %d |  |     |", a -> content);
		else if ((a -> content >= 100 && a -> content < 1000)
			|| (a -> content <= -10 && a -> content > -100))
			printf("\n| %d |  |     |", a -> content);
		else if ((a -> content >= 1000 && a -> content < 10000)
			|| (a -> content <= -100 && a -> content > -1000))
			printf("\n| %d|  |     |", a -> content);
		else
			printf("\n|%d|  |     |", a -> content);
		a = a -> next;
	}
	while (y > x && b)
	{
		if (b -> content >= 0 && b -> content < 10)
			printf("\n|     |  |  %d  |", b -> content);
		else if ((b -> content >= 10 && b -> content < 100)
			|| (b -> content < 0 && b -> content > -10))
			printf("\n|     |  |  %d |", b -> content);
		else if ((b -> content >= 100 && b -> content < 1000)
			|| (b -> content <= -10 && b -> content > -100))
			printf("\n|     |  | %d |", b -> content);
		else if ((b -> content >= 1000 && b -> content < 10000)
			|| (b -> content <= -100 && b -> content > -1000))
			printf("\n|     |  | %d|", b -> content);
		else
			printf("\n|     |  |%d|", b -> content);
		b = b -> next;
	}
	printf("\n-------  -------");
	printf("\nStack A  Stack B\nA Count --> %d\nB Count --> %d\n\n",
		data.a_cnt, data.b_cnt);
}
