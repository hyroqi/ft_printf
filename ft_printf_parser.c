/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:01:05 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/01 18:08:04 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int typehandler(va_list inputs, const char format)
{
	int counter;
	
	counter = 0;
	if (format == 'c')
		counter = chandle(va_arg(inputs, int));
	if (format == 's')
		counter = strhandle(va_arg(inputs, char*));
	if (format == 'i' || format == 'd')
		counter = idhandle(va_arg(inputs, int));
	if (format == 'u')
		counter = uhandle(va_arg(inputs, unsigned int));
	if (format == 'x')
		counter = hexhandle(va_arg(inputs, int), 'x');
	if (format == 'X')
		counter = hexhandle(va_arg(inputs, int), 'X');
	if (format == 'p')
		counter = handleptr(va_arg(inputs, unsigned long long));
	if (format == '%')
		counter = write(1, "%", 1);
	return (counter);
}