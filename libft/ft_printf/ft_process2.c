/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:10:05 by craffate          #+#    #+#             */
/*   Updated: 2017/01/20 15:54:58 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_precision_ws(wchar_t *s, int *arr)
{
	wchar_t			*s2;
	wchar_t			*tmp;
	unsigned int	i;
	unsigned int	eb;

	i = 0;
	eb = 0;
	s2 = NULL;
	tmp = ft_wstrnew(arr[2]);
	while (s[i])
	{
		eb += ft_extrabits_alt(s[i]);
		if ((eb + i) >= (unsigned int)arr[2])
		{
			s2 = ft_wstrnew(i);
			ft_wstrcat(s2, tmp);
			free(tmp);
			return (s2);
		}
		tmp[i] = s[i];
		i++;
	}
	free(tmp);
	return (s2);
}

static wchar_t	*ft_precision_s(wchar_t *s, int *arr)
{
	wchar_t			*s2;
	unsigned int	i;

	s2 = ft_wstrnew(arr[2]);
	i = 0;
	while (arr[2]-- > 0)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

static wchar_t	*ft_precision_int(wchar_t *s, int *arr)
{
	wchar_t			*s2;
	unsigned int	i;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[2]);
	i = 0;
	if ((arr[2] == 0 && *s != '0') || arr[2] != 0)
	{
		while (ft_wstrlen(s) < (size_t)arr[2]--)
			ft_wstrcat(s2, L"0");
		*s == '-' ? ft_wstrcat(s2, L"0") : 0;
		ft_wstrcat(s2, s);
	}
	return (s2);
}

wchar_t			*ft_precision(const char spe, wchar_t *s, int *arr)
{
	wchar_t	*s2;

	s2 = NULL;
	if (spe == 'd' || spe == 'D' || spe == 'i' || spe == 'o' || spe == 'O' ||
		spe == 'x' || spe == 'X' || spe == 'u' || spe == 'U' ||
		spe == 'b' || spe == 'B')
		s2 = ft_precision_int(s, arr);
	else if (spe == 's' && !(arr[0] & L))
		s2 = ft_precision_s(s, arr);
	else if (spe == 'S' || (spe == 's' && arr[0] & L))
		s2 = ft_precision_ws(s, arr);
	ft_swapsign(s2, spe, arr);
	s2 = *s != '0' && arr[0] & SHARP && (spe == 'b' || spe == 'B' || spe == 'x'
		|| spe == 'X') ? ft_sharp(s2, spe) : s2;
	free(s);
	return (s2);
}

wchar_t			*ft_wwidth(wchar_t *s, int *arr, size_t eb)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[1]);
	if ((!(arr[0] & ZERO) || arr[0] & MINUS) || arr[2] != -2)
	{
		if (!(arr[0] & MINUS))
		{
			while ((ft_wstrlen(s) + eb) < (size_t)arr[1]--)
				ft_wstrcat(s2, L" ");
			ft_wstrcat(s2, s);
		}
		else if (arr[0] & MINUS && ft_wstrcat(s2, s))
			while ((ft_wstrlen(s) + eb) < (size_t)arr[1]--)
				ft_wstrcat(s2, L" ");
	}
	else
	{
		while ((ft_wstrlen(s) + eb) < (size_t)arr[1]--)
			ft_wstrcat(s2, L"0");
		ft_wstrcat(s2, s);
		if (ft_wstrchr(s2, '-') && (*ft_wstrchr(s2, '-') = '0'))
			s2[0] = '-';
	}
	free(s);
	return (s2);
}
