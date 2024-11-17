/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:04:52 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/29 17:52:38 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int				data;
	int				index;
	int				pos;
	struct stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
int		check_input(int ac, t_stack **a, char *av[]);
int		just_spaces(char *av);
int		cnt_words(char **str);
long	ft_atoi(const char *s);
int		is_number(char *str);
void	ft_free_tab(char **tab);
t_stack	*create_node(int n);
t_stack	*ft_get_last(t_stack *a);
void	ft_addback(t_stack **a, t_stack *new);
void	free_stack(t_stack **head);
int		is_sorted(t_stack *a);
void	ft_sort(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		get_min(t_stack **a);
void	fix_index(t_stack **a);
t_stack	*ft_get_before_last(t_stack *a);
void	rev_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	sort_with_chunk(t_stack **a, t_stack **b);
int		size_of(t_stack *a);
void	sort_pos(t_stack **a);
void	chunks_to_b(t_stack **a, t_stack **b);
void	chunks_to_a(t_stack **a, t_stack **b);

#endif