/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <search.h>

t_builtin	g_builtins[6] = {
	{b_echo, 6, "echo"},
	{b_cd, 4, "cd"},
	{b_setenv, 8, "setenv"},
	{b_unsetenv, 10, "unsetenv"},
	{b_env, 7, "env"},
	{b_exit, 6, "exit"}
};

int				builtincmp(const void *p1, const void *p2)
{
	char	*s1;
	char	*s2;

	s1 = ((char *)p1);
	s2 = ((t_builtin *)p2)->name;
	return (ft_strcmp(s1, s2));
}

char			**sh_parse(char *line)
{
	return (ft_strsplit(line, ' '));
}

int				sh_exec(char **args)
{
	t_builtin	*builtin;
	size_t 		nbbuiltin;

	if (!args)
		return (1);
	if (!(*args))
		return (1);
	nbbuiltin = sizeof(builtins) / sizeof(builtins[0]);
	builtin = lfind(args[0], g_builtins, &nbbuiltin,
					sizeof(g_builtins[0]), builtincmp);
	if (builtin)
	{
		return (builtin->f(args));
	}
	/* else if (args[0] in PATH) */
	/* 	; */
	return (1);
}

int				sh_loop(void)
{
	int			status;
	char		*line;
	char		**args;

	status = 1;
	while (status)
	{
		ft_putstr(PROMPT);
		get_next_line(0, &line);
		args = sh_parse(line);
		status = sh_exec(args);
		free(line);
		free(args);
	}
	return (0);
}

int				main(int ac, char **av)
{
	if (ac && *av && environ)
		sh_loop();
	return (0);
}
