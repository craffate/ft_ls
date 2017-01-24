/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:57:01 by craffate          #+#    #+#             */
/*   Updated: 2017/01/19 07:34:40 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_preprocesspercent(void)
{
	wchar_t	*s;

	s = ft_wstrdup(L"%");
	return (s);
}

static wchar_t	*ft_preprocessuint(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	s = NULL;
	if (spe == 'x' || spe == 'X')
		s = ft_preprocesshex(spe, ap, arr);
	else if (spe == 'o' || spe == 'O')
		s = ft_preprocessoct(spe, ap, arr);
	else if (spe == 'b' || spe == 'B')
		s = ft_preprocessbin(spe, ap, arr);
	else if (spe == 'u' || spe == 'U')
		s = ft_preprocessuns(spe, ap, arr);
	return (s);
}

static wchar_t	*ft_preprocessint(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH)
		s = ft_llitoa_base((signed char)va_arg(ap, int), 10, spe);
	else if (arr[0] & H)
		s = ft_llitoa_base((short int)va_arg(ap, int), 10, spe);
	else if ((arr[0] & L && spe == 'd') || spe == 'D')
		s = ft_llitoa_base(va_arg(ap, long int), 10, spe);
	else if (arr[0] & LL)
		s = ft_llitoa_base(va_arg(ap, long long int), 10, spe);
	else if (arr[0] & J)
		s = ft_llitoa_base(va_arg(ap, intmax_t), 10, spe);
	else if (arr[0] & Z)
		s = ft_llitoa_base(va_arg(ap, size_t), 10, spe);
	else if (spe == 'p' || spe == 'P')
		s = ft_llitoa_base((long long)va_arg(ap, void *), 16, spe);
	else
		s = ft_llitoa_base(va_arg(ap, int), 10, spe);
	return (s);
}

static wchar_t	*ft_preprocessstr(const char spe, va_list ap, int *arr)
{
	char	*s;
	wchar_t	*ws;

	ws = NULL;
	if (spe == 's' && !(arr[0] & L))
	{
		s = va_arg(ap, char *);
		if (!(s == NULL))
			ws = ft_strtowstr(s);
		else
			ws = ft_wstrdup(L"(null)");
	}
	else if (spe == 'S' || (spe == 's' && arr[0] & L))
	{
		ws = va_arg(ap, wchar_t *);
		if (ws == NULL)
			ws = ft_wstrdup(L"(null)");
		else
			ws = ft_wstrdup(ws);
	}
	return (ws);
}

wchar_t			*ft_preprocess(const char spe, va_list ap, int *arr, int *i)
{
	char	*tmp;
	wchar_t	*wtmp;

	tmp = ft_strnew(1);
	wtmp = NULL;
	wtmp = ft_isint(spe) ? ft_preprocessint(spe, ap, arr) : wtmp;
	wtmp = ft_isunint(spe) ? ft_preprocessuint(spe, ap, arr) : wtmp;
	if (spe == 'c' && !(arr[0] & L))
	{
		*tmp = va_arg(ap, int);
		wtmp = ft_strtowstr(tmp);
	}
	if (spe == 'C' || (spe == 'c' && arr[0] & L))
	{
		wtmp = ft_wstrnew(1);
		*wtmp = va_arg(ap, wint_t);
	}
	wtmp = spe == 'S' || spe == 's' ? ft_preprocessstr(spe, ap, arr) : wtmp;
	wtmp = spe == '%' ? ft_preprocesspercent() : wtmp;
	*i += *wtmp == 0 && (spe == 'c' || spe == 'C') ? 1 : 0;
	*i += ft_extrabits(wtmp);
	free(tmp);
	return (wtmp);
}
