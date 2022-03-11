/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:37 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/09 20:23:29 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*list_new(int a)
{
	t_stack	*c;

	c = (t_stack *)malloc(sizeof(t_stack));
	c -> next = NULL;
	c -> content = a;
	return (c);
}

t_stack	*list_addback(t_stack *a, t_stack *b)
{
	t_stack	*c;

	c = a;
	if (a == NULL)
		return (b);
	while (a -> next != NULL)
		a = a -> next;
	a -> next = b;
	return (c);
}

t_stack	*list_last(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp -> next)
	{
		tmp = tmp -> next;
	}
	return (tmp);
}

int	list_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

int	error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}
