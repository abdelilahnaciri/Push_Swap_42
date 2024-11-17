/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:54:44 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 15:37:03 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leak() {
	system("leaks push_swap");
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (tmp->data < a->data)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	free(current);
}

int	size_of(t_stack *a)
{
	t_stack	*cur;
	int		i;

	cur = a;
	i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	if (size_of(*a) == 2)
		sa(a);
	else if (size_of(*a) == 3)
		sort_three(a);
	else if (size_of(*a) == 4)
		sort_four(a, b);
	else if (size_of(*a) == 5)
		sort_five(a, b);
	else
		sort_with_chunk(a, b);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!check_input(ac, &a, av))
	{
		if (a != NULL) {
			free_stack(&a);
		}
		write(2, "Error\n", 7);
		exit(1);
	}
	else if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	ft_sort(&a, &b);
	// atexit(leak);
}
