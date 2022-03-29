/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:00:11 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/29 20:33:08 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intjoin(int *a, int tmp, int i)
{
	int	*c;
	int	j;

	j = 0;
	c = (int *)malloc(sizeof(int) * i);
	if (!c)
		return (NULL);
	while (j < i - 1)
	{
		c[j] = a[j];
		j++;
	}
	c[j] = tmp;
	free(a);
	return (c);
}

int	num_check(int tmp, t_data *data)
{
	static int	i;
	static int	*a;
	int			j;

	(*data).count = i++;
	j = 0;
	if (i == 1)
	{
		a = (int *)malloc(sizeof(int) * 1);
		if (!a)
			return (0);
		a[0] = tmp;
	}
	else
	{
		while (j < i - 1)
		{
			if (a[j] == tmp)
				return (hayirlisi(a));
			j++;
		}
		a = ft_intjoin(a, tmp, i);
	}
	(*data).s = a;
	return (1);
}

t_stack	*free_v2(char *str)
{
	free(str);
	return (0);
}

t_stack	*split_atoi(t_stack *lst, char **str, t_data *data)
{
	int		i;
	int		j;
	int		tmp;
	char	**tom;
	t_stack	*ls;

	i = 1;
	while (str[i])
	{
		tom = ft_split(str[i], ' ');
		j = 0;
		while (tom[j])
		{
			tmp = ft_atoi_v2(tom[j], data);
			if (!num_check(tmp, data) || !(*data).chk)
				return (free_v2(tom[j]));
			ls = list_new(tmp);
			lst = list_addback(lst, ls);
			free(tom[j]);
			j++;
		}
		free(tom);
		i++;
	}
	free((*data).s);
	return (lst);
}

t_stack	*ft_atol(t_stack *lst, char **str, t_data *data)
{
	int	i;
	int	j;

	(*data).chk = 1;
	i = 1;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j])
		{
			if (!(ft_isdigit(str[i][j]) || str[i][j] == ' ' || ((str[i][j] == '-'
				|| str[i][j] == '+') && ft_isdigit(str[i][j + 1]))))
			{
				error();
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (split_atoi(lst, str, data));
}
