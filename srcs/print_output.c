/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:16:02 by jwilliam          #+#    #+#             */
/*   Updated: 2022/03/23 12:20:42 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Prints the output of performed moves.
*/
void	print_moves(char *move)
{
	ft_putstr_fd(move, 1);
	ft_putchar_fd('\n', 1);
	return ;
}
