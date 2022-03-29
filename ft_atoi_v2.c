#include "push_swap.h"

int	error_v2(t_data *data)
{
	error();
	(*data).chk = 0;
	return(0);
}

int	ft_atoi_v2(const char *str, t_data *data)
{
	int	i;
	int	a;
	long	tmp;

	i = 0;
	a = 1;
	tmp = 0;
	while (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + str[i] - 48;
		if ((a == 1 && tmp > 2147483647) || (a == -1 && tmp > 2147483648))
			return(error_v2(data));
		i++;
	}
	return (tmp * a);
}
