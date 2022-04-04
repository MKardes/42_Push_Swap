#include "push_swap.h"

int    error_v2(t_data *data)
{
    error();
    (*data).chk = 0;
    return (0);
}

int    ft_atoi_v2(const char *str, t_data *data)
{
    int        i;
    int        a;
    long    tmp;

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
            return (error_v2(data));
        i++;
    }
    return (tmp * a);
}

int    *ft_intjoin(int *a, int tmp, int i)
{
    int    *c;
    int    j;

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

int    num_check(int tmp, t_data *data)
{
    static int    i;
    static int    *a;
    int            j;

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

t_stack    *free_v2(char *str)
{
    free(str);
    return (0);
}

t_stack    *split_atoi(t_stack *lst, char **str, t_data *data)
{
    int        i;
    int        j;
    int        tmp;
    char    **tom;
    t_stack    *ls;

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

t_stack    *ft_atol(t_stack *lst, char **str, t_data *data)
{
    int    i;
    int    j;

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

void    ft_pa(t_stack **a, t_stack **b, t_data *data)
{
    t_stack    *tmp;
    t_stack    *tmp_b;

    if (!*b)
        return ;
    tmp = *b;
    tmp_b = *b;
    *b = tmp_b -> next;
    tmp -> next = *a;
    *a = tmp;
    steps("pa\n", data, PA);
}

void    ft_pb(t_stack **a, t_stack **b, t_data *data)
{
    t_stack    *tmp;
    t_stack    *tmp_a;

    if (!*a)
        return ;
    tmp = *a;
    tmp_a = *a;
    *a = tmp_a -> next;
    tmp -> next = *b;
    *b = tmp;
    steps("pb\n", data, PB);
}

void    ft_rra(t_stack **a, int i, t_data *data)
{
    t_stack    *last2;
    t_stack    *tmp;
    t_stack    *first;

    last2 = get_last2(*a);
    tmp = last2 -> next;
    tmp -> next = *a;
    last2 -> next = NULL;
    *a = tmp;
    if (i == 1)
        steps("rra\n", data, -1);
}

void    ft_rrb(t_stack **b, int i, t_data *data)
{
    t_stack    *last2;
    t_stack    *tmp;
    t_stack    *first;

    last2 = get_last2(*b);
    tmp = last2 -> next;
    tmp -> next = *b;
    last2 -> next = NULL;
    *b = tmp;
    if (i == 1)
        steps("rrb\n", data, -1);
}

void    ft_rrr(t_stack **a, t_stack **b, t_data *data)
{
    ft_rra(a, 2, data);
    ft_rrb(b, 2, data);
    steps("rrr\n", data, -1);
}

void    ft_ra(t_stack **a, int i, t_data *data)
{
    t_stack    *first;
    t_stack    *last;

    first = *a;
    last = get_listlast(*a);
    last -> next = first;
    *a = first -> next;
    first -> next = NULL;
    if (i == 1)
        steps("ra\n", data, RA);
}

void    ft_rb(t_stack **b, int i, t_data *data)
{
    t_stack    *first;
    t_stack    *last;

    first = *b;
    last = get_listlast(*b);
    last -> next = first;
    *b = first -> next;
    first -> next = NULL;
    if (i == 1)
        steps("rb\n", data, RB);
}

void    ft_rr(t_stack **a, t_stack **b, t_data *data)
{
    ft_ra(a, 2, data);
    ft_rb(b, 2, data);
    steps("rr\n", data, RR);
}

void    ft_sa(t_stack *a, int i, t_data *data)
{
    int    tmp;

    tmp = a -> content;
    a -> content = a -> next -> content;
    a -> next -> content = tmp;
    if (i == 1)
        steps("sa\n", data, SA);
}

void    ft_sb(t_stack *b, int i, t_data *data)
{
    int    tmp;

    tmp = b -> content;
    b -> content = b -> next -> content;
    b -> next -> content = tmp;
    if (i == 1)
        steps("sb\n", data, SB);
}

void    ft_ss(t_stack *a, t_stack *b, t_data *data)
{
    ft_sa(a, 2, data);
    ft_sb(b, 2, data);
    steps("ss\n", data, SS);
}

int is_rx(t_stack *a, t_stack *b)
{
    t_stack *a_last;
    t_stack *b_last;
    int        c;

    c = 0;
    a_last = list_last(a);
    b_last = list_last(b);
    if (!b)
    {
        if (a -> content > a_last -> content)
            return (RA);
        return (-1);
    }
    if (a -> content > a_last -> content && b -> content < b_last -> content)
        return (RR);
    else if (b -> content < b_last -> content)
        return (RB);
    if (a -> content > a_last -> content)
        return (RA);
    return (-1);
}

int    is_sx(t_stack *a, t_stack *b)
{
    if (a -> content > a -> next -> content && b -> content < b -> next -> content)
        return (SS);
    if (b -> content < b -> next -> content)
        return (SB);
    if (a -> content > a -> next -> content)
        return (SA);
    return (-1);
}

//STACK PRİNT
void    stack_print(t_stack *a, t_stack *b, t_data data)
{
    int    x;
    int    y;

    x = list_size(a);
    y = list_size(b);
    printf("\n\n-------  -------");
    while (a != NULL && b != NULL)
    {
        if (a -> content >= 0 && a -> content < 10)
            printf("\n|  %d  |  ", a -> content);
        else if ((a -> content >= 10 && a -> content < 100)
            || (a -> content < 0 && a -> content > -10))
            printf("\n|  %d |  ", a -> content);
        else if ((a -> content >= 100 && a -> content < 1000)
            || (a -> content <= -10 && a -> content > -100))
            printf("\n| %d |  ", a -> content);
        else if ((a -> content >= 1000 && a -> content < 10000)
            || (a -> content <= -100 && a -> content > -1000))
            printf("\n| %d|  ", a -> content);
        else
            printf("\n|%d|  ", a -> content);
        if (b -> content >= 0 && b -> content < 10)
            printf("|  %d  |", b -> content);
        else if ((b -> content >= 10 && b -> content < 100)
            || (b -> content < 0 && b -> content > -10))
            printf("|  %d |", b -> content);
        else if ((b -> content >= 100 && b -> content < 1000)
            || (b -> content <= -10 && b -> content > -100))
            printf("| %d |", b -> content);
        else if ((b -> content >= 1000 && b -> content < 10000)
            || (b -> content <= -100 && b -> content > -1000))
            printf("| %d|", b -> content);
        else
            printf("|%d|", b -> content);
        a = a -> next;
        b = b -> next;
    }
    while (x > y && a)
    {
        if (a -> content >= 0 && a -> content < 10)
            printf("\n|  %d  |  |     |", a -> content);
        else if ((a -> content >= 10 && a -> content < 100)
            || (a -> content < 0 && a -> content > -10))
            printf("\n|  %d |  |     |", a -> content);
        else if ((a -> content >= 100 && a -> content < 1000)
            || (a -> content <= -10 && a -> content > -100))
            printf("\n| %d |  |     |", a -> content);
        else if ((a -> content >= 1000 && a -> content < 10000)
            || (a -> content <= -100 && a -> content > -1000))
            printf("\n| %d|  |     |", a -> content);
        else
            printf("\n|%d|  |     |", a -> content);
        a = a -> next;
    }
    while (y > x && b)
    {
        if (b -> content >= 0 && b -> content < 10)
            printf("\n|     |  |  %d  |", b -> content);
        else if ((b -> content >= 10 && b -> content < 100)
            || (b -> content < 0 && b -> content > -10))
            printf("\n|     |  |  %d |", b -> content);
        else if ((b -> content >= 100 && b -> content < 1000)
            || (b -> content <= -10 && b -> content > -100))
            printf("\n|     |  | %d |", b -> content);
        else if ((b -> content >= 1000 && b -> content < 10000)
            || (b -> content <= -100 && b -> content > -1000))
            printf("\n|     |  | %d|", b -> content);
        else
            printf("\n|     |  |%d|", b -> content);
        b = b -> next;
    }
    printf("\n-------  -------");
    printf("\nStack A  Stack B\nA Count --> %d\nB Count --> %d\n\n", data.a_cnt, data.b_cnt);
}
//STACK PRİNT

int    hayirlisi(int *a)
{
    error();
    free(a);
    return (0);
}

t_stack    *get_listlast(t_stack *x)
{
    while (x -> next)
        x = x -> next;
    return (x);
}

t_stack    *get_last2(t_stack *x)
{
    while (x -> next -> next)
        x = x -> next;
    return (x);
}

t_stack    *list_new(int a)
{
    t_stack    *c;

    c = (t_stack *)malloc(sizeof(t_stack));
    c -> next = NULL;
    c -> content = a;
    return (c);
}

t_stack    *list_addback(t_stack *a, t_stack *b)
{
    t_stack    *c;

    c = a;
    if (a == NULL)
        return (b);
    while (a -> next != NULL)
        a = a -> next;
    a -> next = b;
    return (c);
}

t_stack    *list_last(t_stack *a)
{
    t_stack    *tmp;

    tmp = a;
    if (!a)
        return (NULL);
    while (tmp -> next)
    {
        tmp = tmp -> next;
    }
    return (tmp);
}

int    list_size(t_stack *lst)
{
    int    i;

    i = 0;
    while (lst)
    {
        lst = lst -> next;
        i++;
    }
    return (i);
}

int    error(void)
{
    ft_putstr_fd("Error\n", 1);
    return (0);
}

t_step *step_new(char *str, int format)
{
    t_step *new;

    new = (t_step *)malloc(sizeof(t_step));
    new -> next = NULL;
    new -> content = str;
    new -> format = format;
    return (new);
}

t_step *step_addback(t_step *real, t_step *add)
{
    t_step *c;

    c = real;
    if (real    == NULL)
        return (add);
    while (real -> next != NULL)
        real = real -> next;
    real -> next = add;
    return (c);
}

void steps(char *rs, t_data *data, int format)
{
    t_step *tmp;
    char    *str;

    str = ft_strdup(rs);
    tmp = step_new(str, format);
    data -> steps = step_addback(data -> steps, tmp);
}

int    del_step_check(t_data *data, t_step *tmp, t_step **iter)
{
    (*data).rev_pa_cnt = (*data).pa_cnt;
    while (tmp -> next && !(*data).pb_cnt && (*data).rev_pa_cnt > 0 && tmp -> format == PB)
    {
        tmp = tmp -> next;
        (*data).rev_pa_cnt--;
    }
    (*data).rev_pb_cnt = (*data).pb_cnt;
    while (tmp -> next && !(*data).pa_cnt && (*data).rev_pb_cnt > 0 && tmp -> format == PA)
    {
        tmp = tmp -> next;
        (*data).rev_pb_cnt--;
    }
    if (!(*data).pb_cnt)
        (*data).pa_cnt = 2 * ((*data).pa_cnt - (*data).rev_pa_cnt);
    if (!(*data).pa_cnt)
        (*data).pb_cnt = 2 * ((*data).pb_cnt - (*data).rev_pb_cnt);
    (*data).cnt = (*data).rev_pa_cnt;
    if (!(*data).cnt)
        (*data).cnt = (*data).rev_pb_cnt;
    if ((*data).pa_cnt != 0 || (*data).pb_cnt != 0)
    {
        while ((*data).cnt-- > 1)
               (*iter) = (*iter) -> next;
        return (1);
    }
    return (0);
}

void    del_step(t_step *iter)
{
    char    *a;
    t_step *tmp;

    a = iter -> content;
    tmp = iter;
    free(a);
    free(tmp);
}

void    del_steps(t_data *data, t_step **iter)
{
    t_step    *tmp;
    int    i;
    int    k;

    i = 0;
    k = (*data).pa_cnt;
    if (!k)
        k = (*data).pb_cnt;
    while (i < k && (*iter) -> next -> next)
    {
        tmp = (*iter) -> next -> next;
        del_step((*iter) -> next);
        (*iter) -> next = tmp ;
        i++;
    }
}

void    get_simple(t_data *data)
{
    t_step    *iter;
    t_step    *tmp;

    iter = (*data).steps;
    (*data).pa_cnt = 0;
    (*data).pb_cnt = 0;
    while (iter -> next)
    {
        tmp = iter;
        while (tmp -> next && tmp -> format == PB && !(*data).pa_cnt)
        {
            (*data).pb_cnt++;
            tmp = tmp -> next;
        }
        while (tmp -> next && tmp -> format == PA && !(*data).pb_cnt)
        {
            (*data).pa_cnt++;
            tmp = tmp -> next;
        }
        if (del_step_check(data, tmp, &iter))
            del_steps(data, &iter);
        iter = iter -> next;
        (*data).pa_cnt = 0;
        (*data).pb_cnt = 0;
    }
}

void    rr_check(t_stack **a, t_stack **b, t_data *data)
{
    int rx;

    rx = is_rx(*a, *b);
    if (rx == RA)
        ft_ra(a, 1, data);
    else if (rx == RB)
        ft_rb(b, 1, data);
    else if (rx == RR)
        ft_rr(a, b, data);
}

void    ss_check(t_stack **a, t_stack **b, t_data *data)
{
    int    sx;

    if (!*b)
    {
        if ((*a) -> content > (*a) -> next -> content)
            ft_sa(*a, 1, data);
        return ;
    }
    if (!((*a) -> next) || !((*b) -> next))
    {
        if (!((*b) -> next) && (*a) -> content > (*a) -> next -> content)
            ft_sa(*a, 1, data);
        else if (!((*a) -> next) && (*b) -> content < (*b) -> next -> content)
            ft_sb(*b, 1, data);
        return ;
    }
    sx = is_sx(*a, *b);
    if (sx == SA)
        ft_sa(*a, 1, data);
    else if (sx == SB)
        ft_sb(*b, 1, data);
    else if (sx == SS)
        ft_ss(*a, *b, data);
}

int    a_check(t_stack *a)
{
    while (a -> next)
    {
        if (a -> content > a -> next -> content)
            return (0);
        a = a -> next;
    }
    return (1);
}

int b_check(t_stack *b)
{
    if (!b)
        return (1);
    while (b -> next)
    {
        if (b -> content < b -> next -> content)
            return (0);
        b = b -> next;
    }
    return (1);
}

int    all_check(t_stack **a, t_stack **b)
{
    if (a_check(*a) && b_check(*b))
    {
        if ((*a) -> content < (*b) -> content)
            return (1);
    }
    return (0);
}

void    move_to_b(t_stack **a, t_stack **b, t_data *data)
{
    while ((*data).a_cnt > (*data).a_rst)
    {
        rr_check(a, b, data);
        ss_check(a, b, data);
        ft_pb(a,b, data);
        (*data).a_cnt--;
        (*data).b_cnt++;
    }
}

int    move_a_check(t_stack **a, t_stack **b, t_data *data)
{
    if (a_check(*a))
    {
        if ((*a) -> content > (*b) -> content && b_check(*b))
        {
            return (1);
        }
    }
    return (0);
}

void    move_to_a(t_stack **a, t_stack **b, t_data *data)
{
    while ((*data).b_cnt > (*data).b_rst)
    {
        rr_check(a, b, data);
        ss_check(a, b, data);
        ft_pa(a, b, data);
        (*data).b_cnt--;
        (*data).a_cnt++;
    }
}

void    start(t_stack **a, t_stack **b, t_data *data)
{
    (*data).count += 1;
    (*data).a_cnt = (*data).count;
    (*data).b_cnt = 0;
    //while (!(all_check(a, b, &(*data).gecici)))
    int    i = 0;
    while (i < 4)
    {
        move_to_b(a, b, data);
        //stack_print(*a, *b, *data);
        move_to_a(a, b, data);
        (*data).a_rst = 2;
        (*data).b_rst = 2;
        //stack_print(*a, *b, *data);
        i++;
    }
}

int    main(int ac, char **av)
{
    t_stack    *a;
    t_stack    *b;
    t_data    data;
    data.a_rst = 2;
    data.b_rst = 2;
    data.steps = NULL;
    int        i;

    b = NULL;
    a = NULL;
    a = ft_atol(a, av, &data);
    start(&a, &b, &data);
    stack_print(a, b, data);
    get_simple(&data);
    return (0);
}
