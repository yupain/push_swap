/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:26:00 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/21 19:56:17 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print(t_stack *stack)
{
	t_intl	*buf;

	if (!stack)
		return ;
	buf = stack->ints;
	
	if (stack->sp == 1)
		write(1, "a = ", 4);
	if (stack->sp == 2)
		write(1, "b = ", 4);
	while (buf)
	{
		printf("|%d|", buf->ind);
		buf = buf->next;
	}
	printf("\n");
}

int	ps_n_ln(t_intl *n)
{
	t_intl	*buf;
	int		i;

	i = 1;
	if (!n)
		return (0);
	buf = n;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	return (i);
}

int	ps_st_ln(t_stack *stack)
{
	int		i;
	t_intl	*buf;

	i = 1;
	if (!stack->ints)
		return (0);
	buf = stack->ints;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	return (i);
}

void	ps_swap(t_stack *stack, int i)
{
	t_intl	*buf;

	if (!ps_st_ln(stack))
	{
		if (stack->sp == 1 && i == 0)
			write(1, "sa\n", 3);
		else if (stack->sp == 2 && i == 0)
			write(1, "sb\n", 3);
		return ;
	}
	if (ps_st_ln(stack) != 1)
	{
		buf = stack->ints;
		stack->ints = stack->ints->next;
		buf->next = stack->ints->next;
		stack->ints->next = buf;
		if (ps_st_ln(stack) == 2)
			stack->intl = stack->ints->next;
	}
	if (stack->sp == 1 && i == 0)
		write(1, "sa\n", 3);
	else if (stack->sp == 2 && i == 0)
		write(1, "sb\n", 3);
}

void	ps_swapall(t_push *push)
{
	ps_swap(push->a, 1);
	ps_swap(push->b, 1);
	write(1, "ss\n", 3);
}

void	ps_push_a(t_push *push)
{
	t_intl	*buf;
	
	if (ps_st_ln(push->b))
	{
		buf = push->b->ints;
		push->b->ints = push->b->ints->next;
		buf->next = push->a->ints;
		push->a->ints = buf;
	}
	if (ps_st_ln(push->a) == 2)
		push->a->intl = push->a->ints->next;
	if ((ps_st_ln(push->b) == 1))
		push->b->intl = NULL;
	write(1, "pa\n", 3);
}

void	ps_push_b(t_push *push)
{
	t_intl	*buf;
	
	if (ps_st_ln(push->a))
	{
		buf = push->a->ints;
		push->a->ints = push->a->ints->next;
		buf->next = push->b->ints;
		push->b->ints = buf;
	}
	if (ps_st_ln(push->b) == 2)
		push->b->intl = push->b->ints->next;
	if ((ps_st_ln(push->a) == 1))
		push->a->intl = NULL;
	write(1, "pb\n", 3);
}

void	ps_rotate(t_stack *stack, int i)
{
	if (ps_st_ln(stack) != 1 && ps_st_ln(stack))
	{
		stack->intl->next = stack->ints;
		stack->intl = stack->intl->next;
		stack->ints = stack->ints->next;
		stack->intl->next = NULL;
	}
	if (i == 1)
		write(1, "ra\n", 3); //rotate_a
	if (i == 2)
		write(1, "rb\n",3); //rotate_b
}

void	ps_rotate_all(t_push *push)
{
	ps_rotate(push->a, 0);
	ps_rotate(push->b, 0);
	write(1, "rr\n",3);
}
//
void	ps_r_rotate(t_stack *stack, int i)
{
	t_intl	*buf;

	if (ps_st_ln(stack) == 1 || !ps_st_ln(stack))
		return ;
	buf = stack->ints;
	while(buf->next->next)
		buf = buf->next;
	buf->next = NULL;
	stack->intl->next = stack->ints;
	stack->ints = stack->intl;
	buf = stack->ints;
	while(buf->next)
		buf = buf->next;
	stack->intl = buf;
	if (i == 1)
		write(1, "rra\n", 4); //r_rotate_a
	if (i == 2)
		write(1, "rrb\n", 4); //r_rotate_b 
}

void	ps_r_all_rotate(t_push *push)
{
	ps_r_rotate(push->a, 0);
	ps_r_rotate(push->b, 0);
	write(1, "rrr\n", 4);
}
//check