/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:39:34 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 15:24:38 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
After up_to_3 is handled, find the highest values in Stack B and use
approximation to move those values to Stack A.
*/
static void	sort_through_b(t_stacks *stacks)
{
	int		split;
	int		num_index;

	up_to_3(stacks);
	while (stacks->b_items > 0)
	{
		split = stacks->b_items / 2;
		num_index = check_item_pos(stacks->stack_b,
				highest_num(stacks->stack_b));
		if (stacks->stack_b->num == highest_num(stacks->stack_b))
		{
			pa(stacks);
		}
		else if (split > num_index)
			rb(stacks, 1);
		else
			rrb(stacks, 1);
	}
	return ;
}

/*
Using approximation, check what the closest value inside the chunk is and
make the appropriate moves to it.
*/
static void	go_through_chunk(t_stacks *stacks, int key)
{
	if (stacks->stack_a->num < key)
		pb(stacks);
	else if (check_top_half(stacks->stack_a, (stacks->a_items / 2), key)
		< check_bot_half(stacks->stack_a, (stacks->a_items / 2), key))
		ra(stacks, 1);
	else
		rra(stacks, 1);
	return ;
}

/*
Using approximation, check where the lowest value is and
make the appropriate moves to it.
*/
static void	go_through_last_chunk(t_stacks *stacks)
{
	int		lowest;
	int		split;
	int		num_index;

	lowest = lowest_num(stacks->stack_a);
	split = (stacks->a_items / 2);
	num_index = check_item_pos(stacks->stack_a, lowest);
	if (stacks->stack_a->num == lowest)
		pb(stacks);
	else if (split > num_index)
		ra(stacks, 1);
	else
		rra(stacks, 1);
	return ;
}

/*
Used to retrieve a key number, or highest number if it is the last chunk.
*/
static int	get_key_num(t_stacks *stacks, int chunk_size, int chunk)
{
	int		key;

	if (chunk >= 5)
		key = (highest_num(stacks->sorted_stack));
	else
		key = find_key_num(stacks->sorted_stack, chunk_size, chunk);
	return (key);
}

/*
Function determines the size of a chunk by dividing the amount of entries in
Stack A by 5. The size of the chunk is check against by the presorted Stack
to determine the key number which is a threshold used to retrieve numbers
in Stack to push them into Stack B.

After Stack B receives up to the size of the chunk, the chunk is incremented
where a new key number is retrieved.

When it is up to the last chunk, changes to retrieving the lowest number and
pushing them to Stack B based on proximity.
*/
void	up_to_100(t_stacks *stacks)
{
	int		key_num;
	int		chunk_size;
	int		chunk;

	chunk_size = ((stacks->a_items / 5));
	chunk = 1;
	key_num = find_key_num(stacks->sorted_stack, chunk_size, chunk);
	while (is_stack_sorted(stacks) == 0)
	{
		if (stacks->a_items <= 3)
		{
			sort_through_b(stacks);
			break ;
		}
		if (chunk < 5)
			go_through_chunk(stacks, key_num);
		else
			go_through_last_chunk(stacks);
		if (stacks->b_items == (chunk_size * chunk) && chunk < 5)
		{
			chunk++;
			key_num = get_key_num(stacks, chunk_size, chunk);
		}
	}
	return ;
}
