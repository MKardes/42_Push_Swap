#include "push_swap.h"

t_stack	*split_atoi(t_stack *lst, char **str)
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
			tmp = atoi(tom[j]);
			ls = list_new(tmp);
			lst = list_addback(lst, ls);
			free(tom[j]);
			j++;
		}
		free(tom);
		i++;
	}
	return (lst);
}

t_stack	*ft_atol(t_stack *lst, char **str)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	while (str[i] != 0) 
	{
		j = 0;
		while (str[i][j])
		{
			if(!(ft_isdigit(str[i][j]) || str[i][j] == ' ' || str[i][j] == '\0'))
			{
				error();
				return(0);
			}
			j++;
		}
		i++;
	}
	return(split_atoi(lst, str));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	//b = list_fill(b);
	a = ft_atol(a, av);
	int     i = 0;
	while (i++ < 5)
		ft_pb(&a, &b);
	if (!a)
		return(0);
	stack_print(a, b);
	ft_pa(&a, &b);
	stack_print(a, b);
	return(0);
}
