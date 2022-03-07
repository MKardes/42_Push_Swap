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
void	ft_sa(t_stack *a, int i);
void	ft_sb(t_stack *b, int i);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_ra(t_stack **a, int i);
void    ft_rb(t_stack **b, int i);
void    ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a, int i);
void    ft_rrb(t_stack **b, int i);
void    ft_rrr(t_stack **a, t_stack **b);
void    ft_pa(t_stack **a, t_stack **b);
void    ft_pb(t_stack **a, t_stack **b);
t_stack	*get_listlast(t_stack *x);
t_stack	*get_last2(t_stack *x);

#endif
