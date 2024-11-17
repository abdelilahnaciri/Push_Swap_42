/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:58:00 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 17:08:49 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_pos2(t_stack **a, t_stack **b)
{
	rra(a);
	rra(a);
	rra(a);
	pb(a, b);
}

static void	push_min(t_stack **a, t_stack **b)
{
	int	pos;

	pos = get_min(a);
	if (pos == 4)
	{
		rra(a);
		pb(a, b);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (pos == 2)
		handle_pos2(a, b);
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

void	sort_five(t_stack **a, t_stack **b)
{
	push_min(a, b);
	sort_four(a, b);
	pa(b, a);
	fix_index(a);
}
