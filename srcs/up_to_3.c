/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:52:02 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 14:52:08 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Swaps the two numbers in a stack if there is only two items.
*/
static void	swap_two(t_stacks *stacks)
{
	if (stacks->stack_a->num > stacks->stack_a->next->num)
		ra(stacks, 1);
	return ;
}

/*
Used to place numbers into an array for sorting.
*/
static void	get_nums(t_stacks *stacks, int *nums)
{
	t_stack_item	*stack_a;
	int				num_count;

	stack_a = stacks->stack_a;
	num_count = 0;
	while (stack_a != NULL)
	{
		nums[num_count] = stack_a->num;
		stack_a = stack_a->next;
		num_count++;
	}
}

/*
Preset commands to solve all cases where there is only up to three
numbers to sort.
*/
void	up_to_3(t_stacks *stacks)
{
	int		nums[3];

	if (stacks->argc <= 2)
	{
		swap_two(stacks);
		return ;
	}
	get_nums(stacks, nums);
	if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] > nums[0])
		sa(stacks, 1);
	else if (nums[0] > nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] < nums[0])
		ra(stacks, 1);
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] > nums[0])
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
		rra(stacks, 1);
	return ;
}
