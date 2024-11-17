/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:48:15 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 16:46:17 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pos(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	i = 0;
	tmp1 = *a;
	while (tmp1)
	{
		i = 0;
		tmp2 = *a;
		while (tmp2)
		{
			if (tmp1->data < tmp2->data)
				i++;
			tmp2 = tmp2->next;
		}
		tmp1->pos = i;
		tmp1 = tmp1->next;
	}
}

int	set_std(t_stack **a)
{
	int	size_a;
	int	std;

	size_a = size_of(*a);
	if (size_a <= 100)
		std = 20;
	else
		std = 30;
	return (std);
}

void	chunks_to_b(t_stack **a, t_stack **b)
{
	int		std;
	int		size_b;
	t_stack	*tmp;

	size_b = 0;
	std = set_std(a);
	while (*a)
	{
		tmp = *a;
		if (tmp->pos <= size_b)
		{
			pb(a, b);
			size_b++;
		}
		else if (tmp->pos < size_b + std)
		{
			pb(a, b);
			if (size_b > 0)
				rb(b);
			size_b++;
		}
		else
			ra(a);
	}
}

int	get_max_pos(t_stack **b)
{
	t_stack	*tmp;
	int		max;
	int		pos;

	pos = 0;
	max = (*b)->data;
	tmp = *b;
	while (tmp)
	{
		if (max < tmp->data)
		{
			max = tmp->data;
			pos = tmp->index;
		}
		tmp = tmp->next;
	}
	return (pos);
}

void	chunks_to_a(t_stack **a, t_stack **b)
{
	int	size_b;
	int	max;

	size_b = size_of(*b);
	max = 0;
	while (size_b)
	{
		fix_index(b);
		max = get_max_pos(b);
		if (max <= size_b / 2)
		{
			while (max--)
				rb(b);
			pa(b, a);
		}
		else
		{
			while (max++ < size_b -1)
				rrb(b);
			rrb(b);
			pa(b, a);
		}
		size_b--;
	}
}
