/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:42:58 by craffate          #+#    #+#             */
/*   Updated: 2017/01/21 14:13:02 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_space(wchar_t *s)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + 1);
	ft_wstrcat(s2, L" ");
	ft_wstrcat(s2, s);
	free(s);
	return (s2);
}

static wchar_t	*ft_plus(wchar_t *s)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + 1);
	ft_wstrcat(s2, L"+");
	ft_wstrcat(s2, s);
	free(s);
	return (s2);
}

static wchar_t	*ft_width(wchar_t *s, const char spe, int *arr)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[1] + 2);
	if ((!(arr[0] & ZERO) || arr[0] & MINUS) || arr[2] != -2)
	{
		if (!(arr[0] & MINUS))
			ft_widthnomin(s, s2, spe, arr);
		else if (arr[0] & MINUS)
			ft_widthmin(s, s2, spe, arr);
	}
	else
	{
		while (ft_wstrlen(s) < (size_t)arr[1]--)
			ft_wstrcat(s2, L"0");
		ft_wstrcat(s2, s);
		ft_swappref(s2, spe, arr);
		ft_swapsign(s2, spe, arr);
	}
	free(s);
	return (s2);
}

wchar_t			*ft_sharp(wchar_t *s, const char spe)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + 3);
	if (spe == 'x' || spe == 'p')
		ft_wstrcat(s2, L"0x");
	else if (spe == 'X' || spe == 'P')
		ft_wstrcat(s2, L"0X");
	else if (spe == 'o' || spe == 'O')
		ft_wstrcat(s2, L"0");
	else if (spe == 'b')
		ft_wstrcat(s2, L"0b");
	else if (spe == 'B')
		ft_wstrcat(s2, L"0B");
	ft_wstrcat(s2, s);
	free(s);
	return (s2);
}

wchar_t			*ft_process(wchar_t *s, const char spe, int *arr)
{
	wchar_t	*s2;
	size_t	eb;

	s2 = ft_wstrdup(s);
	free(s);
	s2 = arr[2] != -2 && spe != '%' && *s2 ? ft_precision(spe, s2, arr) : s2;
	s2 = arr[0] & SPACE && !(arr[0] & PLUS) && !(ft_wstrchr(s2, '-')) &&
		spe != '%' && spe != 'c' && spe != 'C' && !ft_isunint(spe) ?
		ft_space(s2) : s2;
	s2 = arr[0] & SHARP && ft_isunint(spe) && *s2 != '0' &&
		!((spe == 'x' || spe == 'X') && arr[2] == 0) ? ft_sharp(s2, spe) : s2;
	s2 = spe == 'p' || spe == 'P' ? ft_sharp(s2, spe) : s2;
	s2 = arr[0] & PLUS && (spe == 'd' || spe == 'i' || spe == 'D') &&
		!(s[0] == '-' || s[0] == '+') && spe != '%' ? ft_plus(s2) : s2;
	eb = ft_extrabits(s2);
	s2 = arr[1] != -2 && (ft_wstrlen(s2) + eb) < (size_t)arr[1] && !((arr[0] & L
		&& spe == 's') || spe == 'S') ? ft_width(s2, spe, arr) : s2;
	s2 = arr[1] != -2 && (ft_wstrlen(s2) + eb) < (size_t)arr[1] && ((arr[0] & L
		&& spe == 's') || spe == 'S') ? ft_wwidth(s2, arr, eb) : s2;
	return (s2);
}
