/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:42:04 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/28 15:43:18 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	just_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] == ' ')
		i++;
	if (!av[i])
		return (1);
	return (0);
}

int	cnt_words(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != NULL)
		i++;
	return (i);
}

long	ft_atoi(const char *s)
{
	long	nb;
	int		sign;
	int		i;

	sign = 1;
	nb = 0;
	i = 0;
	while (s[i] && s[i] <= 13)
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			return (0);
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9') && str[i + 1] != '\0')
				return (0);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
		}
		else
			return (0);
		i++;
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}
