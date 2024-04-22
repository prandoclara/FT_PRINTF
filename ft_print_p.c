/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:45:45 by claprand          #+#    #+#             */
/*   Updated: 2024/04/22 17:08:25 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *ptr, int *len)
{
	unsigned long long	address;
	char				*digits;

	address = (unsigned long long)ptr;
	digits = "0123456789abcdef";
	if (!address)
	{
		write (1, "(nil)", 5);
		*len = 5;
		return (*len);
	}
	if (address >= 16)
	{
		*len = ft_print_p((void *)(address / 16), len);
		*len = ft_print_p((void *)(address % 16), len);
	}
	else
	{
		ft_putchar_fd(digits[address], 1);
		(*len)++;
	}
	return (*len);
}
