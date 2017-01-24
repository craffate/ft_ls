/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:01:17 by craffate          #+#    #+#             */
/*   Updated: 2017/01/09 17:31:15 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_savele(unsigned short i, const char *s)
{
	if (*s == 'h')
	{
		if (*s + 1 == 'h')
			i = HH;
		else
			i = H;
	}
	if (*s == 'l')
	{
		if (*s + 1 == 'l')
			i = LL;
		else
			i = L;
	}
	i = *s == 'j' ? J : i;
	i = *s == 'z' ? Z : i;
	return (i);
}

int	ft_savefl(unsigned short i, const char c)
{
	i = c == '#' ? SHARP : i;
	i = c == '0' ? ZERO : i;
	i = c == '-' ? MINUS : i;
	i = c == '+' ? PLUS : i;
	i = c == ' ' ? SPACE : i;
	return (i);
}
