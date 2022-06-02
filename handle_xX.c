/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:28 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/02 21:14:30 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	hexconv(unsigned int num, const char bors)
{
	if (num >= 16)
	{
		hexconv(num / 16, bors);
		hexconv(num % 16, bors);
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

int	hexhandle(unsigned int num, const char bors)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		hexconv(num, bors);
	return (hexlen(num));
}
