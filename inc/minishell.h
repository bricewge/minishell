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
# define PROMPT "$> "

typedef struct		s_builtin
{
	int				(*f)(char **args);
	int				len;
	char			name[11];
}					t_builtin;

/* typedef struct		s_arr */
/* { */
/* 	void			*base; */


/* } */
int					sh_loop(void);
char				**sh_parse(char *line);
int					sh_exec(char **args);
/*
** Builtins functions
*/
int					b_echo(char **args);
int					b_cd(char **args);
int					b_setenv(char **args);
int					b_unsetenv(char **args);
int					b_env(char **args);
int					b_exit(char **args);
/*
** Functions which ought to be moved in my libft.
*/


extern char			**environ;
extern t_builtin	builtins[6];

#endif
