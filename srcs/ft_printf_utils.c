/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:32 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/16 17:19:55 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
