/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:10:05 by hgabriel          #+#    #+#             */
/*   Updated: 2022/06/15 05:20:08 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//Main printf function
int		ft_printf(const char *str, ...);

//Type handler
int		typehandler(va_list inputs, const char format);

//Handle Handler
int		chandle(char c);
int		idhandle(int n);
int		handleptr(unsigned long long ptr);
int		strhandle(const char *str);
int		uhandle(unsigned int n);
int		hexhandle(unsigned int num, const char bors);
int		ptrhandle(unsigned long long num, const char bors);
void	ptrconv(unsigned long long num, const char bors);
int		ptrlen(unsigned	long long num);

//Utilities
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa_base16(unsigned long long num);
char	*ft_rev(char *str);

#endif