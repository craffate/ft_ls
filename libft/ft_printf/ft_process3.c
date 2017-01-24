/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:06:01 by craffate          #+#    #+#             */
/*   Updated: 2017/01/19 07:57:24 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_widthnomin(wchar_t *s, wchar_t *s2, const char spe, int *arr)
{
	while (ft_wstrlen(s) < (size_t)arr[1]--)
	{
		if (*s == 0 && (spe == 'c' || spe == 'C') &&
			ft_wstrlen(s) == (size_t)arr[1])
			break ;
		ft_wstrcat(s2, L" ");
	}
	ft_wstrcat(s2, s);
}

void	ft_widthmin(wchar_t *s, wchar_t *s2, const char spe, int *arr)
{
	ft_wstrcat(s2, s);
	while (ft_wstrlen(s) < (size_t)arr[1]--)
	{
		if (*s == 0 && (spe == 'c' || spe == 'C') &&
			ft_wstrlen(s) == (size_t)arr[1])
			break ;
		ft_wstrcat(s2, L" ");
	}
}

void	ft_swappref(wchar_t *s, const char spe, int *arr)
{
	if (arr[0] & SHARP && arr[0] & ZERO)
	{
		if (spe == 'x')
		{
			*ft_wstrchr(s, 'x') = '0';
			s[1] = 'x';
		}
		else if (spe == 'X')
		{
			*ft_wstrchr(s, 'X') = '0';
			s[1] = 'X';
		}
	}
}

void	ft_swapsign(wchar_t *s, const char spe, int *arr)
{
	if ((arr[0] & ZERO && ft_isint(spe)) || (ft_isint(spe) && arr[2] != -2))
	{
		if (ft_wstrchr(s, '+'))
		{
			*ft_wstrchr(s, '+') = '0';
			s[0] = '+';
		}
		else if (ft_wstrchr(s, '-'))
		{
			*ft_wstrchr(s, '-') = '0';
			s[0] = '-';
		}
	}
}
