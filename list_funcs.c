#include "push_swap.h"

t_stack *list_new(int a)
{
    t_stack *c;

    c = (t_stack*)malloc(sizeof(t_stack));
    c -> next = NULL;
    c -> content = a;
    return (c);
}

t_stack *list_addback(t_stack *a, t_stack *b)
{
    t_stack *c;

    c = a;
    if (a == NULL)
        return(b);
    while (a -> next != NULL)
        a = a -> next;
    a -> next = b;
    return (c);
}

t_stack	*list_last(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp -> next)
	{
		tmp = tmp -> next;
	}
	return (tmp);
}

int list_size(t_stack *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst -> next;
        i++;
    }
    return (i);
}

// Bu önemsiz;
void    list_printer(t_stack *a)
{
	printf("\n| PRINT LIST |\n\n");
    while (a)
    {
        printf("%d\n", a -> content);
        a = a -> next;
    }
}

int error(void)
{
    ft_putstr_fd("Hata!", 1);
    return (0);
}

t_stack *list_fill(t_stack *a)
{
    int i;
    int x[] = {23, 11230, 1770, 9034, 2110, 52, 120, 283};
    t_stack *s;

    i = 0;
    while (x[i] != 283)
    {
        s = list_new(x[i]);
        a = list_addback(a, s);
        i++;
    }
    return (a);
}

t_stack	*get_listlast(t_stack *x)
{
	while (x -> next)
		x = x -> next;
	return (x);
}

t_stack	*get_last2(t_stack *x)
{
	while (x -> next -> next)
		x = x -> next;
	return (x);
}
