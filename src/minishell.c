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

int				sh_loop(void)
{
	int			i;
	int			status;
	char		*line;
	char		**cmds;
	char		**args;

	status = 0;
	while (status >= 0)
	{
		ft_putstr(PROMPT);
		get_next_line(0, &line);
		cmds = ft_strsplit(line, ';');
		i = -1;
		while (cmds[++i] && status >= 0)
		{
			args = sh_parse(cmds[i], status);
			status = sh_exec(args, status);
			ft_freearr(args);
		}
		ft_freearr(cmds);
		free(line);
	}
	return (status < 0 ? 0 : status);
}

int				main(int ac, char **av, char **envp)
{
	ft_environ(envp);
	ft_environ(NULL);
	signals();
	if (ac && *av)
		return (sh_loop());
	return (0);
}
