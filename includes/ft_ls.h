/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:56:26 by craffate          #+#    #+#             */
/*   Updated: 2017/02/13 13:19:38 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <dirent.h>

# define LS_L (1 << 0)
# define LS_CR (1 << 1)
# define LS_A (1 << 2)
# define LS_R (1 << 3)
# define LS_T (1 << 4)
# define LS_F (1 << 5)
# define LS_U (1 << 6)
# define MUL_ARGS (1 << 7)

# define USAGE "\x1b[33m[ft_ls]\x1b[0m usage: ft_ls [-lRartfu] [file ...]\n"
# define DENIED "\x1b[33m[ft_ls]\x1b[0m Permission denied\n"

typedef struct stat	t_stat;

typedef struct		s_file
{
	char			*name;
	char			*path;
	t_stat			stat;
}					t_file;

int					ft_ls(t_file *dir, int i);
int					ft_ls_parse(const char *s);
t_file				**insert(t_file **args, t_file *file, int fl);
t_file				*create_struct(char *name, char *path);
void				display_l(t_file *dir, size_t *schars);
void				display_nl(t_file *dir);
void				display(t_file **dir, int i, size_t *schars);
void				freetab(t_file **tab);
char				*join_path(char *s1, char *s2);
void				maxsizechars(t_file **args, size_t *schars);
size_t				*arrnew(size_t s);
long long int		total(t_file **dir);
int					execcheck(t_file *file);
size_t				gettotals(t_file **files, t_file **dirs);
void				getsizes(size_t *schars, t_file **files, t_file **dirs);
char				*getdate_ls(time_t t);
char				rights_type(t_file *file);
int					cmp(t_file *file, t_file *args, int fl);
int					pathcheck(char *s, int i);

#endif
