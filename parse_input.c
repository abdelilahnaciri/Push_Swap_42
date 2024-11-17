/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:01:22 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 17:03:42 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_and_push(t_stack **a, int value)
{
	t_stack	*new;

	new = create_node(value);
	if (!new)
		return (0);
	ft_addback(a, new);
	return (1);
}

int	is_dup(t_stack *a)
{
	t_stack	*head;

	head = NULL;
	while (a)
	{
		head = a->next;
		while (head)
		{
			if (head->data == a->data)
				return (0);
			head = head->next;
		}
		a = a->next;
	}
	return (1);
}

int	continue_checking(t_stack **a, char *av[], char **splited_inputs, int i)
{
	int		j;
	int		len;

	len = 0;
	j = 0;
	if (av[i][0] == '\0' || just_spaces(av[i]))
		return (0);
	splited_inputs = ft_split(av[i], 32);
	len = cnt_words(splited_inputs);
	if (len == -1)
		return (ft_free_tab(splited_inputs), 0);
	while (j < len)
	{
		if (!is_number(splited_inputs[j]))
			return (ft_free_tab(splited_inputs), 0);
		if (!add_and_push(a, ft_atoi(splited_inputs[j])))
			return (ft_free_tab(splited_inputs), 0);
		j++;
	}
	j = 0;
	ft_free_tab(splited_inputs);
	i++;
	return (1);
}

int	check_input(int ac, t_stack **a, char *av[])
{
	char	**splited_inputs;
	int		ac_nums;
	int		i;

	ac_nums = ac - 1;
	i = 1;
	splited_inputs = NULL;
	while (av[i] && i <= ac_nums)
	{
		if (!continue_checking(a, av, splited_inputs, i))
			return (0);
		i++;
	}
	if (!is_dup(*a))
		return (0);
	return (1);
}
