/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:37:56 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/07 14:59:31 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*
Generic error when a duplicate number is found in input arguments
*/
void	dupe_numbers(void)
{
	ft_putstr_fd("Error", 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}

/*
Generic error when a non integer is used in arguments
*/
void	invalid_int(void)
{
	ft_putstr_fd("Error", 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}
