/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"
# define PROMPT "❯ "
# define NB_BUILTINS 8

typedef struct		s_bltin
{
	int				(*f)(char **args);
	int				len;
	char			name[11];
}					t_bltin;
typedef struct		s_arr
{
	const void		*base;
	size_t			*nel;
	size_t			width;
}					t_arr;
int					sh_loop(void);
char				**sh_parse(char *line);
int					sh_exec(char **args);
t_bltin				*builtins(void);
/*
** Builtins functions
*/
int					b_echo(char **args);
int					b_cd(char **args);
int					b_setenv(char **args);
int					b_unsetenv(char **args);
int					b_env(char **args);
int					b_exit(char **args);
int					b_true(char **args);
int					b_false(char **args);
/*
** Functions which ought to be moved in my libft
*/
char				*ft_stpcpy(char *dst, const char *src);
void				*ft_lfind(const void *key, t_arr array,
							int (*compar)(const void *, const void *));
char				*ft_pathjoin(const char *dir, const char *file);
int					ft_puterror(char *msg, char *name, int errnum);
void				ft_freearr(char **pstr);

char				**ft_environ(char **envp);
char				*ft_getenv(const char *name);
int					ft_setenv(const char *envname, const char *envvalue,
								int overwrite);
int					ft_putenv(char *string);
int					ft_unsetenv(const char *name);

#endif
