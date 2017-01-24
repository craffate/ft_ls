/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:30:15 by craffate          #+#    #+#             */
/*   Updated: 2017/01/20 15:42:58 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <locale.h>

# define H (1 << 0)
# define HH (1 << 1)
# define L (1 << 2)
# define LL (1 << 3)
# define J (1 << 4)
# define Z (1 << 5)
# define SHARP (1 << 6)
# define ZERO (1 << 7)
# define MINUS (1 << 8)
# define PLUS (1 << 9)
# define SPACE (1 << 10)
# define EOC (L"\x1b[0m")
# define RED (L"\x1b[31m")
# define GREEN (L"\x1b[32m")
# define YELLOW (L"\x1b[33m")
# define BLUE (L"\x1b[34m")
# define MAGENTA (L"\x1b[35m")
# define CYAN (L"\x1b[36m")
# define WHITE (L"\x1b[37m")

int			ft_printf(const char *format, ...);
const char	*ft_parse(int *arr, const char *format, va_list ap);
int			ft_isspecifier(const char c);
int			ft_isflag(const char c);
int			ft_islength(const char c);
int			ft_savefl(unsigned short i, const char c);
int			ft_savele(unsigned short i, const char *s);
int			ft_isint(const char c);
int			ft_isunint(const char c);
int			ft_isdouble(const char c);
wchar_t		*ft_preprocess(const char spe, va_list ap, int *arr, int *i);
wchar_t		*ft_process(wchar_t *s, const char spe, int *arr);
wchar_t		*ft_llitoa_base(long long n, unsigned int b, const char spe);
wchar_t		*ft_ullitoa_base(unsigned long long n, unsigned int b,
			const char spe);
size_t		ft_extrabits(const wchar_t *s);
wchar_t		*ft_strtowstr(char *s);
wchar_t		*ft_wstrj2(wchar_t *s1, const wchar_t *s2);
wchar_t		*ft_wwidth(wchar_t *s, int *arr, size_t eb);
const char	*ft_colors(const char *format, wchar_t **s);
wchar_t		*ft_precision(const char spe, wchar_t *s, int *arr);
size_t		ft_extrabits_alt(const int c);
wchar_t		*ft_preprocessbin(const char spe, va_list ap, int *arr);
wchar_t		*ft_preprocesshex(const char spe, va_list ap, int *arr);
wchar_t		*ft_preprocessoct(const char spe, va_list ap, int *arr);
wchar_t		*ft_preprocessuns(const char spe, va_list ap, int *arr);
void		ft_swappref(wchar_t *s, const char spe, int *arr);
void		ft_swapsign(wchar_t *s, const char spe, int *arr);
void		ft_widthmin(wchar_t *s, wchar_t *s2, const char spe, int *arr);
void		ft_widthnomin(wchar_t *s, wchar_t *s2, const char spe, int *arr);
wchar_t		*ft_sharp(wchar_t *s, const char spe);

#endif
