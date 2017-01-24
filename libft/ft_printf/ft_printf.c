/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:56:49 by craffate          #+#    #+#             */
/*   Updated: 2017/01/21 14:14:54 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_formatcat(wchar_t **s1, const char *format)
{
	size_t	i;
	size_t	j;
	wchar_t	*tmp;

	i = 0;
	j = 0;
	while (format[j] && format[j] != '%' && format[j] != '{')
		j++;
	tmp = ft_wstrnew(j);
	while (j > 0)
	{
		tmp[i++] = *format++;
		j--;
	}
	*s1 = ft_wstrj2(*s1, tmp);
	free(tmp);
	return (format);
}

static int			ft_check(int *arr, const char *format)
{
	return ((arr[0] & MINUS || arr[0] & PLUS || arr[0] & SPACE
	|| arr[0] & SHARP || arr[0] & ZERO) || arr[1] != -2 ||
	arr[2] != -2 || *format == 'p' || *format == 'P') ? 1 : 0;
}

static	void		ft_norme(int *arr, wchar_t *s, va_list ap)
{
	arr[0] = ft_wstrlen(s);
	ft_putwstr(s);
	free(s);
	va_end(ap);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		arr[3];
	wchar_t	*s;
	wchar_t	*tmp;
	int		i;

	tmp = NULL;
	s = ft_wstrnew(0);
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (format = ft_parse(arr, format, ap)))
		{
			tmp = ft_preprocess(*format, ap, arr, &i);
			ft_check(arr, format) ? tmp = ft_process(tmp, *format, arr) : 0;
			s = ft_wstrj2(s, tmp);
			free(tmp);
			format++;
		}
		*format == '{' ? format = ft_colors(format, &s) : 0;
		*format != 37 ? format = ft_formatcat(&s, format) : 0;
	}
	ft_norme(arr, s, ap);
	return (arr[0] + i);
}
