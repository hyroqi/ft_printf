/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:25 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/02 20:40:07 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strhandle(const char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (str == NULL)
	{
		str2 = "(null)";
		while (str2[i])
		{
			write(1, &str2[i], 1);
			i++;
		}
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
//     char    *str;

//     str = "HelloWorld";

//     printf("\nStrlen : %d", strhandle(str));

//     return (0);
// }