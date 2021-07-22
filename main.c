/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:32:14 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/22 17:57:39 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free(t_push *push);

static int	ret_err(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}

static int	num_check(char **argv)
{
	int	i;
	int	k;
	
	k = 1;
	while (argv[k])
	{
		i = 0;
		while (ft_isdigit(argv[k][i]) || argv[k][i] == '-' || argv[k][i] == '+')
			i++;
		if (argv[k][i] != '\0' && !(ft_isdigit(argv[k][i])))
			return (0);
		k++;
	}
	return (1);
}

static void	put_last_a(t_intl *k, t_push *push)
{
	
	if (!(push->a->ints))
	{
		push->a->ints = malloc(sizeof(t_intl));
		push->a->ints->i = k->i;
		push->a->ints->next = NULL;
		push->a->intl = push->a->ints;
	}
	else
	{
		push->a->intl->next = malloc(sizeof(t_intl));
		push->a->intl->next->i = k->i;
		push->a->intl->next->next = NULL;
		push->a->intl = push->a->intl->next;
	}
}

long long	ps_atoi(char *str)
{
	int			i;
	int		 	pt;
	int			k;
	long long	num;

	i = 0;
	pt = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pt = -1;
		i++;
	}
	while (str[i])
	{
		k = str[i++] - '0';
		num = k + (num * 10);
		if (num > 2147483647)
			return (2147483648);
	}
	return (num * pt);
}

int put_ind(t_push *push)
{
	t_intl *buf1;
	t_intl *buf2;
	int		ind;
	
	buf1 = push->a->ints;
	while (buf1 != NULL)
	{
		ind = 0;
		buf2 = push->a->ints;
		while (buf2)
		{
			if ((int)buf1->i > (int)buf2->i)
				ind++;
			if ((int)buf1->i == (int)buf2->i && buf1 != buf2)
			{
				write(1, "Error\n", 6);
				ps_free(push);
				return (0);
			}
			buf2 = buf2->next;
		}
		buf1->ind = ind;
		buf1 = buf1->next;
	}
	return (1);
}

int	init_struct(t_push *push)
{
	push->a = malloc(sizeof(t_stack));
	push->b = malloc(sizeof(t_stack));
	if (!push->a || !push->b)
		return (0);
	push->a->ints = NULL;
	push->a->intl = NULL;
	push->a->sp = 1;
	push->b->ints = NULL;
	push->b->intl = NULL;
	push->b->sp = 2;
	push->sort_fl = 0;
	return (1);
}

int		ps_get_med(t_stack *stack)
{
	t_intl	*buf;
	int		i;

	i = 0;
	buf = stack->ints;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	return (i / 2);
}

void	get_ind(t_push *push)
{
	t_intl	*buf;
	int		i;

	i = 0;
	buf = push->a->ints;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	push->max_ind = i;
	push->med_ind = ps_get_med(push->a);
}

void	ps_sort_a_3(t_push *push)
{
	if (push->a->ints->ind == 0)
	{
		if (push->a->ints->next->ind == push->med_ind)
			ps_r_rotate(push->a, 1);
		else
			ps_swap(push->a, 0);
	}
	else if (push->a->ints->next->ind == 0)
	{
		if (push->a->ints->ind == push->med_ind)
		{
			ps_swap(push->a, 0);
			ps_r_rotate(push->a, 1);
		}
	}
	else if (push->a->intl->ind == 0)
	{
		if (push->a->ints->next->ind == push->med_ind)
			ps_swap(push->a, 0);
		ps_rotate(push->a, 1);
	}
}

void	ps_b_fill(t_push *push)
{
	while (ps_st_ln(push->a) != 3)
	{
		if (push->a->ints->ind == 0 || push->a->ints->ind == push->max_ind
			|| push->a->ints->ind == push->med_ind)
			ps_rotate(push->a, 1);
		else
		{
			ps_push_b(push);
			if (push->med_ind > push->b->ints->ind)
				ps_rotate(push->b, 2);
		}
	}
	ps_sort_a_3(push);
}

int	ps_find(t_push *push, t_intl *b_int)
{
	int		i;
	t_intl	*buf;
	
	i = 1;
	buf = push->a->ints;
	if (push->a->ints->ind > b_int->ind && push->a->intl->ind < b_int->ind
		&& push->a->intl->ind != push->max_ind && push->a->ints->ind != 0)
		return (0);
	while (buf->next)
	{
		if (buf->ind > b_int->ind && buf->next->ind < b_int->ind
			&& buf->next->ind != 0 && buf->ind != push->max_ind)
			return (i);
		else if (buf->ind < b_int->ind && buf->next->ind > b_int->ind
				&& buf->next->ind != 0 && buf->ind != push->max_ind)
			return (i);
		i++;
		buf = buf->next;
	}
	return (i);
}

int		ps_b_find(t_push *push)
{
	t_intl	*buf;
	t_intl	*buf1;
	int		i;
	int		i_a;
	int		k;
	int		j;
	
	// (void)push;
	i = ps_find(push, push->b->ints);
	if (i > (ps_st_ln(push->a) / 2))
			i = ps_st_ln(push->a) - i;
	// printf("\ni = %d\n\n", i);
	k = 0;
	j = 0;
	if (i == 0)
		return (0);
	buf = push->b->ints;
	buf1 = push->b->ints;
	while (buf)
	{
		i_a = ps_find(push, buf);
		if (i_a > (ps_st_ln(push->a) / 2))
			i_a = ps_st_ln(push->a) - i_a;
		// printf("\ni_a = %d\ni_ind_b = %d\n\n", i_a, buf->ind);
		if ((i > (i_a + k) && k < (ps_st_ln(push->a) / 2)))
		{
			i = i_a + k;
			buf1 = buf;
			j = k;
		}
		else if ((i > (i_a + (ps_st_ln(push->b)) - k) && k >= (ps_st_ln(push->a) / 2)))
		{
			i = i_a + (ps_st_ln(push->b)) - k;
			// printf("\ni = %d|  i > (i_a + (ps_st_ln(push->a) / 2) - k)\n\n", i);
			buf1 = buf;
			j = k;
		}
		k++;
		buf = buf->next;
	}
	// printf("\ni = %d\nj = %d\n\n", i, j);
	// ps_print(push->a);
	// ps_print(push->b);
	if (j > (ps_st_ln(push->b) / 2))
		j = j - ps_st_ln(push->b);
	// printf("\nj = %d\n", j);
	if (j > 0)
		while (j-- > 0)
			ps_rotate(push->b, 2);
	else if (j < 0)
		while (j++ < 0)
			ps_r_rotate(push->b, 2);
	// ps_print(push->a);
	// ps_print(push->b);
	return (ps_find(push, push->b->ints));
}

void	ps_a_fill(t_push *push)
{
	int	i;
	
	while (ps_st_ln(push->b))
	{
		i = ps_b_find(push);
		// ps_print(push->a);
		// ps_print(push->b);
		if (i > (ps_st_ln(push->a) / 2))
			i = i - ps_st_ln(push->a);
		if (i == 0)
			ps_push_a(push);
		else if (i > 0)
		{
			while (i-- > 0)
				ps_rotate(push->a, 1);
			ps_push_a(push);
		}
		else if (i < 0)
		{
			while (i++ < 0)
				ps_r_rotate(push->a, 1);
			ps_push_a(push);
		}
	}
}

void	ps_a_to_up(t_stack *stack)
{
	t_intl	*buf;
	int		i;

	buf = stack->ints;
	i = 0;
	while (buf->ind != 0)
	{
		buf = buf->next;
		i++;
	}
	if (i > (ps_st_ln(stack) / 2))
		i = i - ps_st_ln(stack);
	if (i > 0)
		while (i-- > 0)
			ps_rotate(stack, 1);
	else if (i < 0)
		while (i++ < 0)
			ps_r_rotate(stack, 1);
}

void	sorter(t_push *push)
{
	t_intl	*buf;
	// int		i;

	buf = push->a->ints;
	// write (1, "kek\n",4);
	get_ind(push);
	// ps_print(push->a);
	// printf("-%d-\n", ps_st_ln(push->a));
	// printf("%d", push->med_ind);
	if (ps_st_ln(push->a) >= 3)
		ps_b_fill(push);
	else if (ps_st_ln(push->a) == 2 && push->a->ints->ind != 0)
		ps_swap(push->a, 0);
	// ps_print(push->a);
	// ps_print(push->b);
	// write(1,"to_a--------------------\n",25);
	// i = ps_b_find(push);
	// printf("\n!%d!\n", i);
	// write (1, "kek\n",4);
	if (ps_st_ln(push->b))
		ps_a_fill(push);
	ps_a_to_up(push->a);
	// ps_print(push->a);
	// ps_print(push->b);
}

void	ps_free(t_push *push)
{
	t_intl	*buf;
	t_intl	*fbuf;

	if (push->a->ints)
	{
		buf = push->a->ints;
		while (buf)
		{
			fbuf = buf;
			buf = buf->next;
			free(fbuf);
		}
	}
	if (push->b->ints)
	{
		buf = push->b->ints;
		while (buf)
		{
			fbuf = buf;
			buf = buf->next;
			free(fbuf);
		}
	}
	free(push->a);
	free(push->b);
}

int	ps_if_sorted(t_stack *stack)
{
	t_intl	*buf;

	buf = stack->ints;
	while (buf->next)
	{
		if ((buf->ind + 1) != (buf->next->ind))
			return (1);
		buf = buf->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_push	push;
	t_intl	k;
	
	if (argc == 2)
		return (0);
	if (argc < 2 || !(num_check(argv)) || !(init_struct(&push)))
		return (ret_err());
	i = 1;
	// write (1, "kek\n",4);
	while (argv[i])
	{
		k.i = ps_atoi(argv[i]);
		if (k.i == 2147483648)
			return (ret_err());
		put_last_a(&k, &push);
		i++;
	}
	
	if (!put_ind(&push))
		return (0);
	// write (1, "kek\n",4);
	// if (!(ps_if_sorted(push.a)))
	// {
	// 	ps_free(&push);
	// 	return (0);
	// }
	sorter(&push);
	
	ps_free(&push);
	return (0);
}
