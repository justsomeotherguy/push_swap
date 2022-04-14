/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:34:31 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/07 15:02:03 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Prints the contents of Stack A and the amount of moves made.
*/
/*
static void	print_stacks(t_stacks *stacks)
{
	ft_putstr_fd("Stack A", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(" --- ", 1);
	ft_putchar_fd('\n', 1);
	while (stacks->stack_a != NULL)
	{
		ft_putnbr_fd(stacks->stack_a->num, 1);
		ft_putchar_fd('\n', 1);
		stacks->stack_a = stacks->stack_a->next;
	}
	ft_printf("Moves made - %i", stacks->moves);
	ft_putchar_fd('\n', 1);
}
*/

/*
Create Stack A from the numbers received in **argv, will check if there is
any duplicate numbers before adding the number to Stack A.
*/
static void	populate_stacks(t_stacks *stack, int argc, char **argv)
{
	int					argcindex;

	argcindex = 1;
	while (argcindex < argc)
	{
		check_stack_dupes(stack->stack_a, ft_atoi(argv[argcindex]));
		add_to_stack(&stack->stack_a, init_stack(ft_atoi(argv[argcindex])));
		stack->a_items++;
		argcindex++;
	}
}

/*
Initializes the stack structs to hold all the Stack entries.

After checking if the received arguments are valid numbers, the entries in
Stack A will be added to a separate presorted Stack for finding specific
numbers.

Depending on the amount of numbers added, the Stacks struct will be forwarded
to the appropriate function to sort the numbers.
*/
int	main(int argc, char **argv)
{
	t_stacks		*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	if (argc == 1)
		return (0);
	stacks->argc = argc - 1;
	check_valid_int(argc, argv);
	populate_stacks(stacks, argc, argv);
	presort_stack(stacks);
	if (is_stack_sorted(stacks) == 1)
		return (0);
	if (stacks->argc <= 3)
		up_to_3(stacks);
	else if (stacks->argc <= 5)
		up_to_5(stacks);
	else if (stacks->argc <= 10)
		up_to_10(stacks);
	else if (stacks->argc <= 100)
		up_to_100(stacks);
	else
		up_to_500(stacks);
	return (0);
}
