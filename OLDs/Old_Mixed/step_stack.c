#include "push_swap.h"

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
    if (real	== NULL)
        return (add);
    while (real -> next != NULL)
        real = real -> next;
    real -> next = add;
    return (c);
}

void steps(char *rs, t_data *data, int format)
{
	t_step *tmp;
	char	*str;

	str = ft_strdup(rs);
	tmp = step_new(str, format);
	data -> steps = step_addback(data -> steps, tmp);
}

int	del_step_check(t_data *data, t_step *tmp, t_step **iter)
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

void	del_step(t_step *iter)
{
	char	*a;
	t_step *tmp;

	a = iter -> content;
	tmp = iter;
	free(a);
	free(tmp);
}

void	del_steps(t_data *data, t_step **iter)
{
	t_step	*tmp;
	int	i;
	int	k;

	i = 0;
	k = (*data).pa_cnt;
	if (!k)
		k = (*data).pb_cnt;
	printf("\n\n\n\n\n***********Before_DEL*****DEL_count->%d/%d*******\n",(*data).pa_cnt,(*data).pb_cnt);
	tmp = *iter;
	while ((*iter) -> next)
	{
		printf ("%s",(*iter) -> content);
		(*iter) = (*iter) -> next;
	}
   	*iter = tmp;
	while (i < k && (*iter) -> next -> next)
	{
		tmp = (*iter) -> next -> next;
		del_step((*iter) -> next);
		(*iter) -> next = tmp ;
		i++;
	}
	printf("\n\n\n\n\n******************************\n");
	tmp = *iter;
	while ((*iter) -> next)
	{
		printf ("%s",(*iter) -> content);
		(*iter) = (*iter) -> next;
	}
	*iter = tmp;
}

void	get_simple(t_data *data)
{
	t_step	*iter;
	t_step	*tmp;

	iter = (*data).steps;
	(*data).pa_cnt = 0;
	(*data).pb_cnt = 0;
	printf("-->><<>><<--\n");
	while (iter -> next)
         {
                 printf ("%s",iter -> content);
                 iter = iter -> next;
         }
	iter = (*data).steps;
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
		{
			del_steps(data, &iter);
			printf("\n\n\n\n\n*********LAST******\n");
			tmp = (*data).steps;
			while (tmp -> next)
			{
				printf ("%s",tmp -> content);
				tmp = tmp -> next;
			}
		}
		iter = iter -> next;
		(*data).pa_cnt = 0;
		(*data).pb_cnt = 0;
	}
	/*
	printf("\n\n\n\n\n******************************\n");
	while ((*data).tmp -> next)
	{
		printf ("%s",(*data).tmp -> content);
		(*data).tmp = (*data).tmp -> next;
	}
	*/
}
