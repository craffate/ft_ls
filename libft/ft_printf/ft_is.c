/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:42:05 by craffate          #+#    #+#             */
/*   Updated: 2017/01/19 08:05:09 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isunint(const char c)
{
	return ((c == 'u' || c == 'U' || c == 'O' || c == 'o' || c == 'x'
			|| c == 'X' || c == 'b' || c == 'B') ? 1 : 0);
}

int	ft_isint(const char c)
{
	return ((c == 'd' || c == 'i' || c == 'D' || c == 'p' || c == 'P') ? 1 : 0);
}

int	ft_isspecifier(const char c)
{
	return ((c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' ||
			c == 'P' || c == '%' || c == 'b' || c == 'B') ? 1 : 0);
}

int	ft_isflag(const char c)
{
	return ((c == '-' || c == '+' || c == ' ' || c == '#' || c == '0') ? 1 : 0);
}

int	ft_islength(const char c)
{
	return ((c == 'h' || c == 'l' || c == 'j' || c == 'z') ? 1 : 0);
}
