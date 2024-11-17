/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:28:52 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 16:56:36 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int		max;
	t_stack	*tmp;

	max = (*a)->data;
	tmp = *a;
	while (tmp)
	{
		if (max < tmp->data)
			max = tmp->data;
		tmp = tmp->next;
	}
	if ((*a)->data == max)
		ra(a);
	else if ((*a)->next->data == max)
		rra(a);
	sa(a);
	fix_index(a);
}
