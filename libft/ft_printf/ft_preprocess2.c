/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:20:35 by craffate          #+#    #+#             */
/*   Updated: 2017/01/18 16:08:16 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_preprocessuns(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH || arr[0] & H)
		s = ft_ullitoa_base((unsigned char)va_arg(ap, int), 10, spe);
	else if (arr[0] & H)
		s = ft_ullitoa_base((unsigned short int)va_arg(ap, int), 10, spe);
	else if (arr[0] & L)
		s = ft_ullitoa_base(va_arg(ap, unsigned long int), 10, spe);
	else if (arr[0] & LL)
		s = ft_ullitoa_base(va_arg(ap, unsigned long long int), 10, spe);
	else if (arr[0] & J)
		s = ft_ullitoa_base(va_arg(ap, uintmax_t), 10, spe);
	else if (arr[0] & Z)
		s = ft_ullitoa_base(va_arg(ap, size_t), 10, spe);
	else
		s = ft_ullitoa_base(va_arg(ap, unsigned int), 10, spe);
	return (s);
}

wchar_t	*ft_preprocessbin(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH)
		s = ft_ullitoa_base((unsigned char)va_arg(ap, int), 2, spe);
	else if (arr[0] & H)
		s = ft_ullitoa_base((unsigned short int)va_arg(ap, int), 2, spe);
	else if (arr[0] & L)
		s = ft_ullitoa_base(va_arg(ap, unsigned long int), 2, spe);
	else if (arr[0] & LL)
		s = ft_ullitoa_base(va_arg(ap, unsigned long long int), 2, spe);
	else if (arr[0] & J)
		s = ft_ullitoa_base(va_arg(ap, uintmax_t), 2, spe);
	else if (arr[0] & Z)
		s = ft_ullitoa_base(va_arg(ap, size_t), 2, spe);
	else
		s = ft_ullitoa_base(va_arg(ap, unsigned int), 2, spe);
	return (s);
}

wchar_t	*ft_preprocessoct(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH)
		s = ft_ullitoa_base((unsigned char)va_arg(ap, int), 8, spe);
	else if (arr[0] & H)
		s = ft_ullitoa_base((unsigned short int)va_arg(ap, int), 8, spe);
	else if (arr[0] & L)
		s = ft_ullitoa_base(va_arg(ap, unsigned long int), 8, spe);
	else if (arr[0] & LL)
		s = ft_ullitoa_base(va_arg(ap, unsigned long long int), 8, spe);
	else if (arr[0] & J)
		s = ft_ullitoa_base(va_arg(ap, uintmax_t), 8, spe);
	else if (arr[0] & Z)
		s = ft_ullitoa_base(va_arg(ap, size_t), 8, spe);
	else
		s = ft_ullitoa_base(va_arg(ap, unsigned int), 8, spe);
	return (s);
}

wchar_t	*ft_preprocesshex(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH)
		s = ft_ullitoa_base((unsigned char)va_arg(ap, int), 16, spe);
	else if (arr[0] & H)
		s = ft_ullitoa_base((unsigned short int)va_arg(ap, int), 16, spe);
	else if (arr[0] & L)
		s = ft_ullitoa_base(va_arg(ap, unsigned long int), 16, spe);
	else if (arr[0] & LL)
		s = ft_ullitoa_base(va_arg(ap, unsigned long long int), 16, spe);
	else if (arr[0] & J)
		s = ft_ullitoa_base(va_arg(ap, uintmax_t), 16, spe);
	else if (arr[0] & Z)
		s = ft_ullitoa_base(va_arg(ap, size_t), 16, spe);
	else
		s = ft_ullitoa_base(va_arg(ap, unsigned int), 16, spe);
	return (s);
}
