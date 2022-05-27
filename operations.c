/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:29:11 by mkhedhir          #+#    #+#             */
/*   Updated: 2022/05/25 20:26:43 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h> 

typedef struct s_stack {
    int v;
    struct s_stack *next;
}   t_stack;

void	sa(t_stack **a)
{
	int		tmp;
	t_stack	*tmp_list;

	if ((*a) && (*a)->next)
	{
		tmp_list = (*a);
		tmp = (*a)->next->v;
		(*a)->next->v = (*a)->v;
		(*a)->v = tmp;
	}		
}

void	sb(t_stack **b)
{
	int		tmp;
	t_stack	*tmp_list;

	if ((*b) && (*b)->next)
	{
		tmp_list = (*b);
		tmp = (*b)->next->v;
		(*b)->next->v = (*b)->v;
		(*b)->v = tmp;
	}		
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	if ((*b))
	{
		(*a)->next = (*a);
		(*a) = (*b);
		if ((*b)->next)
			(*b) = (*b)->next;
		else
			free((*b));
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if ((*b))
	{
		(*b)->next = (*b);
		(*b) = (*a);
		if ((*a)->next)
			(*a) = (*a)->next;
		else
			free((*a));
	}
}