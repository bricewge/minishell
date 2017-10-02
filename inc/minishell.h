/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/02 12:35:22 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"
# define PROMPT "\x1B[36m❯ \x1B[0m"
# define NB_BUILTINS (int)8

typedef struct		s_bltin
{
	int				(*f)(char **args);
	int				len;
	char			name[11];
}					t_bltin;

/*
** Global variables
*/
pid_t				g_childpid;

int					sh_loop(void);
char				**sh_parse(char *line, int status);
int					sh_exec(char **args, int status);
t_bltin				*builtins(void);
void				signals(void);
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
** Trivial functions
*/
int					ft_puterror(char *msg, char *name, int errnum);
void				ft_freearr(char **pstr);
#endif
