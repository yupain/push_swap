
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# include <stdio.h> //printf

typedef struct s_intl
{
	long long		i;
	int				ind;
	struct s_intl	*next;
}	t_intl;

typedef struct s_stack
{
	t_intl	*ints;
	t_intl	*intl;
	int		sp;
}	t_stack;

typedef struct s_push
{
	t_stack	*a;
	t_stack	*b;
	int		sort_fl;
	int		med_ind;
	int		max_ind;
}	t_push;

void	ps_swap(t_stack *stack, int i);// swap stack a/b
void	ps_swapall(t_push *push);// stacks swap

void	ps_push_a(t_push *push);// from b to a
void	ps_push_b(t_push *push);// from a to b

void	ps_rotate(t_stack *stack, int i);// 1 -> last
void	ps_rotate_all(t_push *push);

void	ps_r_rotate(t_stack *stack, int i);// last -> 1
void	ps_r_all_rotate(t_push *push);

int		ps_st_ln(t_stack *stack);// list length
int		ps_n_ln(t_intl *n);// n* list lenght

void	ps_print(t_stack *stack);// вывод списка

#endif