/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:48:17 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/28 11:48:28 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_with_chunk(t_stack **a, t_stack **b)
{
	sort_pos(a);
	chunks_to_b(a, b);
	chunks_to_a(a, b);
	fix_index(a);
}
