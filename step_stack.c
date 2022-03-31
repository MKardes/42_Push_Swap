#include "push_swap.h"

t_step *step_new(char *str)
{
	t_step *new;

	new = (t_step *)malloc(sizeof(t_step));
	new -> next = NULL;
	new -> content = str;
	return (new);
}

t_step *step_addback(t_step *real, t_step *add)
{
    t_step *c;

    c = real;
    if (real	== NULL)
        return (add);
    while (real -> next != NULL)
        real = real -> next;
    real -> next = add;
    return (c);
}

void steps(char *rs, t_data *data)
{
	t_step *tmp;
	char	*str;

	str = ft_strdup(rs);
	tmp = step_new(str);
	data -> steps = step_addback(data -> steps, tmp);
}
