/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:52:58 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/06 17:45:32 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>

typedef struct s_stack {
	int	content;
	struct s_stack *next;
}	t_stack;

t_stack	*list_new(int a);
t_stack	*list_addback(t_stack *a, t_stack *b);
t_stack	*list_fill(t_stack *a);
int		list_size(t_stack *lst);
int		error(void);
void	list_printer(t_stack *a);//Önemsiz
void	stack_print(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_ra(t_stack **a);
t_stack	*ft_rb(t_stack *b);
void    ft_rr(t_stack *a, t_stack *b);

#endif
