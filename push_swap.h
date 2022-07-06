/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:27:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/06 17:18:55 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RA 0
# define RRA 1
# define BUFF 30

# include "Libft/libft.h"
# include <stdio.h>

typedef struct s_data {
	int		a_cnt;
	int		b_cnt;
	int		count;
	int		*s;
	int		chk;
	int		i;
	int		j;
	int		last_part;
}	t_data;

typedef struct s_stack {
	int				content;
	struct s_stack	*next;
	int				index;
}	t_stack;

t_stack	*list_new(int a);
t_stack	*list_addback(t_stack *a, t_stack *b);
t_stack	*list_last(t_stack *a);
t_stack	*get_listlast(t_stack *x);
t_stack	*get_last2(t_stack *x);
t_stack	*ft_atol(t_stack *lst, char **str, t_data *data);
int		hayirlisi(int *a);
int		list_size(t_stack *lst);
int		error(void);
int		num_check(int tmp, t_data *data);
int		ft_atoi_v2(const char *str, t_data *data);
int		is_sorted(t_stack *a);
int		index_check(t_stack *a, int k, int i, int j);
void	stack_print(t_stack *a, t_stack *b, t_data data);
void	ft_sa(t_stack *a, int i, t_data *data);
void	ft_sb(t_stack *b, int i, t_data *data);
void	ft_ss(t_stack *a, t_stack *b, t_data *data);
void	ft_ra(t_stack **a, int i, t_data *data);
void	ft_rb(t_stack **b, int i, t_data *data);
void	ft_rr(t_stack **a, t_stack **b, t_data *data);
void	ft_rra(t_stack **a, int i, t_data *data);
void	ft_rrb(t_stack **b, int i, t_data *data);
void	ft_rrr(t_stack **a, t_stack **b, t_data *data);
void	ft_pa(t_stack **a, t_stack **b, t_data *data);
void	ft_pb(t_stack **a, t_stack **b, t_data *data);
void	array_sort(int	**s, int cnt);
void    stack_indisle(t_stack **a, t_data data);
void	partly_sorting(t_stack **a, t_stack **b, t_data *data);
void	algorithm_3(t_stack **a, t_data *data);
void	part_2(t_stack **a, t_stack **b, t_data *data);

#endif
