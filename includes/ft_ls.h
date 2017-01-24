/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:56:26 by craffate          #+#    #+#             */
/*   Updated: 2017/01/24 15:57:46 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>

# define LS_L (1 << 0)
# define LS_CR (1 << 1)
# define LS_A (1 << 2)
# define LS_R (1 << 3)
# define LS_T (1 << 4)

# define ERROR_USAGE "[ft_ls] illegal option\n[ft_ls] usage: ft_ls [-lRart]\n"

typedef struct stat	t_stat;

typedef struct		s_struct
{
	char			*files;
	char			*folders;
	t_stat			stat;
}

int		ft_ls(t_stat stat);
int		ft_ls_parse(char *s);

#endif
