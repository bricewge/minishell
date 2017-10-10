/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/10 17:04:45 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "minishell.h"

static int			bltincmp(const void *p1, const void *p2)
{
	char			*s1;
	char			*s2;

	s1 = ((char *)p1);
	s2 = ((t_bltin *)p2)->name;
	return (ft_strcmp(s1, s2));
}

t_bltin				*builtins(void)
{
	static t_bltin	ret[NB_BUILTINS] = {
		{b_echo, 6, "echo"},
		{b_cd, 4, "cd"},
		{b_setenv, 8, "setenv"},
		{b_unsetenv, 10, "unsetenv"},
		{b_env, 7, "env"},
		{b_exit, 6, "exit"},
		{b_true, 4, "true"},
		{b_false, 5, "false"}
	};

	return (ret);
}

int					ft_execute(char *path, char **args, char **envp)
{
	int				status;

	status = 0;
	if (access(path, F_OK) == -1)
		return (ft_puterror("command not found: ", path, 127));
	else if (access(path, X_OK) == -1)
		return (ft_puterror("permission denied: ", path, 126));
	g_childpid = fork();
	if (g_childpid > 0)
		wait(&status);
	else if (g_childpid == 0)
	{
		execve(path, args, envp);
		exit(ft_puterror("execution error: ", args[0], 1));
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (status);
}

int					sh_launch(char **args)
{
	int				status;
	int				i;
	char			**path;
	char			*exec;

	if (ft_isregfile(args[0]) != 0 && (args[0][0] == '.' || args[0][0] == '/'))
		return (ft_execute(args[0], args, ft_environ(NULL)));
	else if ((path = ft_strsplit(ft_getenv("PATH"), ':')))
	{
		i = -1;
		while (path[++i])
		{
			exec = ft_pathjoin(path[i], args[0]);
			if (access(exec, F_OK) == 0)
			{
				status = ft_execute(exec, args, ft_environ(NULL));
				free(exec);
				ft_freearr(path);
				return (status);
			}
			free(exec);
		}
		ft_freearr(path);
	}
	return (ft_puterror("command not found: ", args[0], 127));
}

int					sh_exec(char **args, int status)
{
	t_bltin			*bltin;
	size_t			nbbltin;

	if (!args || !*args || !**args)
		return (status);
	nbbltin = NB_BUILTINS;
	bltin = ft_lfind(args[0], (t_arr) {builtins(), &nbbltin, sizeof(*bltin)},
						bltincmp);
	if (bltin)
		return (bltin->f(args));
	else
		return (sh_launch(args));
	ft_putendl(args[0]);
	return (status);
}
