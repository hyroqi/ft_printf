/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:23 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/01 18:01:51 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int handleptr(unsigned int ptr)
{
	int	print_length;

	if (!ptr)
		write(1, "nullptr", 7);
	print_length = 0;
	print_length += write(1, "0x", 2);
	print_length += hexhandle(ptr, 'x');
	return (print_length);
}