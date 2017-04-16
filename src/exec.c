/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <search.h>
#include "minishell.h"

static int			bltincmp(const void *p1, const void *p2)
{
	char			*s1;
	char			*s2;

	s1 = ((char *)p1);
	s2 = ((t_bltin *)p2)->name;
	return (ft_strcmp(s1, s2));
}

int				ft_execute(char *path, char **args, char **envp)
{
	int			status;
	pid_t		father;

	status = 0;
	if (access(path, F_OK) == -1)
		return (ft_puterror("command not found: ", path, 127));
	else if (access(path, X_OK) == -1)
		return (ft_puterror("permission denied: ", path, 126));
	father = fork();
	if (father > 0)
		wait(&status);
	else if (father == 0)
	{
		execve(path, args, envp);
		return (ft_puterror("execution error: ", args[0], 1));
	}
	return (status);
}

int				sh_launch(char **args)
{
	int			ret;
	int			i;
	char		**path;
	char		*exec;

	if (args[0][0] == '.' || args[0][0] == '/')
		return (ft_execute(args[0], args, environ));
	else if ((path = ft_strsplit(ft_getenv("PATH"), ':')))
	{
		i = -1;
		while (path[++i])
		{
			exec = ft_pathjoin(path[i], args[0]);
			if (access(exec, F_OK) == 0)
			{
				ret = ft_execute(exec, args, environ);
				free(exec);
				ft_freearr(path);
				return (ret);
			}
			free(exec);
		}
		ft_freearr(path);
	}
	return (ft_puterror("command not found: ", args[0], 127));
}

int				sh_exec(char **args)
{
	t_bltin		*bltin;
	size_t 		nbbltin;

	if (!args || !*args || !**args)
		return (0);
	nbbltin = sizeof(g_bltins) / sizeof(g_bltins[0]);
	bltin = lfind(args[0], g_bltins, &nbbltin,
					sizeof(g_bltins[0]), bltincmp);
	if (bltin)
		return (bltin->f(args));
	else
		return (sh_launch(args));
	ft_putendl(args[0]);
	return (0);
}
