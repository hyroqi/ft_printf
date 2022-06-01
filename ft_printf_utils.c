/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:32 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/01 18:01:39 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	numlen(const int i)
// {
// 	int	len;
// 	int	buffer;

// 	buffer = i;
// 	while (buffer)
// 	{
// 		buffer /= 10;
// 		len++;
// 	}
// 	return (len);
// }


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str;

// 	str = "Hello World";

// 	printf("strlen : %d \n", ft_strlen(str));

// 	return(0);
// }

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// char	*ft_rev(char *str)
// {
// 	size_t		ln;
// 	size_t		i;
// 	size_t		n;
// 	char		c;

// 	n = ft_strlen(str);
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
// 	str[n] = '\0';
// 	return (str);
// }

// char	*ft_itoa_base16(unsigned long long num)
// {
// 	char	res[1024];
// 	int		i;

// 	i = 0;
// 	while (num)
// 	{
// 		res[i] = (num % 16) + '0';
// 		if (res[i] > '9')
// 			res[i] = (num % 16) + ('a' - 10);
// 		num /= 16;
// 		i++;
// 	}
// 	res[i] = 0;
// 	return (ft_rev(res));
// }