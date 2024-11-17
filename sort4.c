/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:44:48 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 17:09:39 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		pos;

	pos = 0;
	min = (*a)->data;
	tmp = *a;
	while (tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			pos = tmp->index;
		}
		tmp = tmp->next;
	}
	return (pos);
}

void	fix_index(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

static void	push_min(t_stack **a, t_stack **b)
{
	int	pos;

	pos = get_min(a);
	if (pos == 3)
	{
		rra(a);
		pb(a, b);
	}
	else if (pos == 2)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (pos == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (pos == 0)
		pb(a, b);
	fix_index(a);
	fix_index(b);
}

void	sort_four(t_stack **a, t_stack **b)
{
	push_min(a, b);
	sort_three(a);
	pa(b, a);
	fix_index(a);
}
