/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:38:24 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/02 20:27:35 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	int		secondcount;
	va_list	inputs;

	i = 0;
	counter = 0;
	secondcount = 0;
	va_start(inputs, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			counter += typehandler(inputs, str[i + 1]);
			i++;
		}
		else
		{
			write (1, &str[i], 1);
			counter += 1;
		}
		i++;
	}
	va_end(inputs);
	return (counter + secondcount);
}
