/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:27:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/03/31 19:59:49 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define sa 0
# define sb 1
# define ss 2
# define ra 0
# define rb 1
# define rr 2

# include "Libft/libft.h"
# include <stdio.h>

typedef struct s_step {
	char			*content;
	struct s_step	*next;
}	t_step;

typedef struct s_data {
	int		a_cnt;
	int		b_cnt;
	int		count;
	int		*s;
	int		chk;
	int		a_rst;
	int		b_rst;
	t_step *steps;
}	t_data;

typedef struct s_stack {
	int				content;
	struct s_stack	*next;
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
int		is_rx(t_stack *a, t_stack *b);
int		is_sx(t_stack *a, t_stack *b);
void 	steps(char *rs, t_data *data);

#endif
