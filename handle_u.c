/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:27 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/02 20:53:41 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_unintlen(const unsigned int n)
{
	unsigned int	x;
	unsigned int	len;

	x = n;
	len = 0;
	if (x == 0)
		len = 1;
	while (x)
	{
		x /= 10;
		len++;
	}
	return (len);
}

char	*ft_unitoa(unsigned int n)
{
	char				*itoa;
	unsigned int		len;

	len = ft_unintlen(n);
	if (n == 0 && len == 1)
		return (ft_strdup("0"));
	itoa = (char *)malloc((len + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	while (n != 0)
	{
		itoa[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (itoa);
}

int	uhandle(unsigned int n)
{
	unsigned int	len;
	unsigned int	i;
	char			*itoad;

	i = 0;
	len = ft_unintlen(n);
	itoad = ft_unitoa(n);
	while (i < len)
	{
		write(1, &itoad[i], 1);
		i++;
	}
	free(itoad);
	return (len);
}
