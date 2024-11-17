/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:07:09 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/28 12:54:00 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_stack	*create_node(int n)
{
	t_stack		*new;
	static int	i;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = n;
	new->index = i;
	new->next = NULL;
	i++;
	return (new);
}

t_stack	*ft_get_last(t_stack *a)
{
	t_stack	*last;

	last = a;
	if (a == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_stack	*ft_get_before_last(t_stack *a)
{
	t_stack	*before_last;

	before_last = a;
	if (a == NULL)
		return (NULL);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	return (before_last);
}

void	ft_addback(t_stack **a, t_stack *new)
{
	t_stack	*last;

	last = ft_get_last(*a);
	if (!last)
	{
		*a = new;
		return ;
	}
	if (last->next == NULL)
		last->next = new;
}
