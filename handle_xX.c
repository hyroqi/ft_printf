/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:28 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/01 16:49:12 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

// static int	ft_intlen(const int n)
// {
//     int x;
// 	int	len;

//     x = n;
// 	len = 0;
// 	if (x < 0)
// 		len++;
// 	if (x == 0)
// 		len = 1;
// 	while (x)
// 	{
// 		x /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_rev(char *str)
// {
// 	size_t		ln;
// 	size_t		i;
// 	char		c;

// 	if (!str)
// 		return (0);
// 	ln = ft_strlen(str) - 1;
// 	i = 0;
// 	c = 0;
// 	while (i < ln)
// 	{
// 		c = str[i];
// 		str[i] = str[ln];
// 		str[ln] = c;
// 		i++;
// 		ln--;
// 	}
// 	return (str);
// }

// char *hexconv(int n, char bors)
// {
//     char    res[1024];
//     int     i;
//     int     offset;

//     i = 0;
//     if (n == 0)
//         return(ft_strdup("0"));
//     if (bors == 'x')
//         offset = 87;
//     else
//         offset = 55;
//     while (n > 0)
//     {
//         res[i] = (n % 16) + '0';
//         if (res[i] > '9')
//             res[i] = (n % 16 + offset);
//         n /= 16;
//         i++;
//     }
//     res[i] = '\0';
//     return (ft_rev(res));
// }

// int	hexhandle(int n, char bors)
// {
// 	int	count;
// 	int	i;
// 	char *hex;

// 	i = 0;
// 	hex = hexconv(n, bors);
// 	count = ft_strlen(hex);
// 	while (hex[i])
// 	{
// 		write(1, &hex[i], 1);
// 		i++;
// 	}
// 	free(hex);
// 	return (count);
// }

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







// #include <stdio.h>

// int main(void)
// {
//     int i = 42069;

// 	printf("\nCharNumber : %d", writehex(i, 'x'));


//     return(0);
// }