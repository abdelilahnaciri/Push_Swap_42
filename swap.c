/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:21:39 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 16:58:04 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	tmp = (*a)->data;
	if ((*a)->data > (*a)->next->data)
	{
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	int	tmp;

	tmp = (*b)->data;
	if ((*b)->data > (*b)->next->data)
	{
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
		write(1, "sb\n", 3);
	}
}
