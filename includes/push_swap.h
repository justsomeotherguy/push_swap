/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:02:23 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 14:19:10 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/includes/libft.h"

# define MAX 2147483647
# define MIN -2147483648

/*
Struct to hold stack values / linked list
	- Stores int value 
	- pointer to next stack value
*/

typedef struct s_stack_item
{
	int						num;
	struct s_stack_item		*next;
}	t_stack_item;

/*
Structs to hold both A and B stack structs.
argc to hold max value for stacks.
ints to count total items in stack to ensure it doesnt exceed argc value.
ints to hold how many items are in the stacks for both A and B.
int to track how many moves have been made.
*/

typedef struct s_stacks
{
	struct s_stack_item		*stack_a;
	struct s_stack_item		*stack_b;
	struct s_stack_item		*sorted_stack;
	int						argc;
	int						a_items;
	int						b_items;
	int						moves;
}	t_stacks;

/*
Stack Handling functions
*/

t_stack_item	*init_stack(int num);

void			add_to_stack(t_stack_item **stack, t_stack_item *append);

t_stack_item	*to_last_item(t_stack_item *stack);

/*
Functions to validate input arguments
*/

void			check_stack_dupes(t_stack_item *stack, int match);

int				check_valid_int(int argc, char **argv);

/*
Make a presorted stack to check for specific numbers in the stack for
chunking and sorting
*/

void			presort_stack(t_stacks *stacks);

/*
Check if Stack A is sorted
*/

int				is_stack_sorted(t_stacks *stack);

/*
Solver Functions
*/

void			up_to_3(t_stacks *stacks);

void			up_to_5(t_stacks *stacks);

void			up_to_10(t_stacks *stacks);

void			up_to_100(t_stacks *stack);

void			up_to_500(t_stacks *stack);

/*
Error Functions
*/

void			dupe_numbers(void);

void			invalid_int(void);

/*
Print Output Functions
*/

void			print_moves(char *move);

/*
Swap Functions
*/

void			sa(t_stacks *stacks, int flag);

void			sb(t_stacks *stacks, int flag);

void			ss(t_stacks *stacks);

/*
Push Functions
*/

void			pa(t_stacks *stacks);

void			pb(t_stacks *stacks);

/*
Rotate Functions
*/

void			ra(t_stacks *stacks, int flag);

void			rb(t_stacks *stacks, int flag);

void			rr(t_stacks *stacks);

/*
Reverse Rotate Functions
*/

void			rra(t_stacks *stacks, int flag);

void			rrb(t_stacks *stacks, int flag);

void			rrr(t_stacks *stacks);

/*
Find Numbers
*/

int				lowest_num(t_stack_item *stack);

int				highest_num(t_stack_item *stack);

int				find_next_lowest(t_stack_item *stack_a, int old_low);

int				find_key_num(t_stack_item *stack, int size, int chunk);

/*
Find Positions In Stack
*/

int				check_top_half(t_stack_item *stack, int items, int num);

int				check_bot_half(t_stack_item *stack, int items, int num);

int				check_item_pos(t_stack_item *stack, int num_to_find);

#endif