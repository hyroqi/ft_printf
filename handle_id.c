/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:21 by hgabriel          #+#    #+#             */
/*   Updated: 2022/05/23 23:50:34 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>


static int	ft_intlen(int n)
{
    int x;
	int	len;

    x = n;
	len = 0;
	if (x < 0)
		len++;
	if (x == 0)
		len = 1;
	while (x)
	{
		x /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;

	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 && len == 1)
		return (ft_strdup("0")); 
	itoa = (char *)malloc((len + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	if (n < 0)
	{
		itoa[0] = '-';
		n = -n;
	}
	itoa[len] = '\0';
	while (n != 0 && len >= 0)
	{
		itoa[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (itoa);
}

int idhandle(int n)
{
    int len;
    int i;
    char *itoad;

    i = 0;
    len = ft_intlen(n);

    itoad = ft_itoa(n);
    while (i < len)
    {
        write(1, &itoad[i], 1);
        i++;
    }
	free(itoad);
    return (len);
}

// #include <stdio.h>

// int main(void)
// {
//     int i = 6942069;
    
//     printf("\nreturned : %d \n", idhandle(i));

//     return(0);


// }