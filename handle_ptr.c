/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:23 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/03 13:29:08 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ptrlen(unsigned	long long num)
{
	long long	len;

	len = 0;
	if (num == 0)
	{
		return(1);
	}
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return ((int)len);
}

void	ptrconv(unsigned long long num, const char bors)
{
	if (num >= 16)
	{
		ptrconv(num / 16, bors);
		ptrconv(num % 16, bors);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (bors == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (bors == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ptrhandle(unsigned long long num, const char bors)
{
	// if (num == 0)
	// 	return (write(1, "0", 1));
	// else
		ptrconv(num, bors);
	return (ptrlen(num));
}

int	handleptr(unsigned long long ptr)
{
	int	print_length;

	// if (!ptr)
	// {
	// 	write(1, "0x0", 4);
	// 	return (3);
	// }
	print_length = 0;
	print_length += write(1, "0x", 2);
	print_length += ptrhandle(ptr, 'x');
	return (print_length);
}
