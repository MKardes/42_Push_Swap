/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:52:54 by mkardes           #+#    #+#             */
/*   Updated: 2022/02/28 20:49:51 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_putstr_fd("Hata!", 1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != 0) 
	{
		j = 0;
		while (av[i][j])
		{
			if(!(ft_isdigit(av[i][j]) || av[i][j] == ' ' || av[i][j] == '\0'))
				return(error());
			j++;
		}
		i++;
	}
	return(0);
}
