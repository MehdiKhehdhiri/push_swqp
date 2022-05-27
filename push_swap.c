/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:55:11 by mkhedhir          #+#    #+#             */
/*   Updated: 2022/05/25 20:55:14 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>


int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	check_sign(const char *str, int i, int *neg)
{
	int	f;

	f = 0;
	if ((str[i] == '-' || str[i] == '+') && !f)
	{
		if (str[i] == '-')
			*neg = -1;
		i++;
		f++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (is_space(nptr[i]))
		i++;
	i = check_sign(nptr, i, &neg);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += (nptr[i] - '0');
		i++;
		if (nb > 2147483647 && neg == 1)
			return (-1);
	}
	if (nb < -2147483648 - 1)
		return (0);
	return ((int)nb * neg);
}

typedef struct s_stack {
    int v;
    struct s_stack *next;
}   t_stack;

void	sa(t_stack **a);

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = (t_stack *) malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->v = content;
	list->next = 0;
	return (list);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if(lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **alst, int new)
{
	t_stack	*l;
	
	if (!*alst)
		*alst = ft_lstnew(new);
	else
	{
		l = ft_lstlast(*alst);
		l->next = ft_lstnew(new);
	}
}

void print_list(t_stack *head) {
    t_stack *current_node = head;
   	while ( current_node != NULL) {
        printf("%d ", current_node->v);
        current_node = current_node->next;
    }
}
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);

int main(int argc, char *argv[])
{
        int             i;
        t_stack  *stack_a;
        t_stack  *stack_b;

        //if (check_args(argc, argv) == -1)
        //{
        //        printf("Error\n");
        //        exit(-1);
        //}
        i = 1;
        stack_a = ft_lstnew(ft_atoi(argv[i++]));
        stack_b = NULL;
        while (i < argc)
        	ft_lstadd_back(&stack_a, ft_atoi(argv[i++]));
//
        //sort(&stack_a, &stack_b);

		pb(&stack_a, &stack_b);
        printf("a : ");
        print_list(stack_a);
        printf("b : ");
        print_list(stack_b);
        return (0);
}