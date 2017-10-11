/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/10/11 17:43:46 by bwaegene         ###   ########.fr       */
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
		if (get_next_line(STDIN_FILENO, &line) <= 0)
			exit(status);
		cmds = ft_strsplit(line, ';');
		i = -1;
		while (cmds[++i] && status >= 0)
		{
			args = sh_parse(cmds[i], status);
			status = sh_exec(args, ft_environ(NULL), status);
			ft_freearr(args);
		}
		ft_freearr(cmds);
		free(line);
	}
	return (status < 0 ? 0 : status);
}

int				main(int ac, char **av, char **envp)
{
	int			ret;

	(void)ac;
	(void)av;
	ret = 1;
	ft_environ(envp);
	signals();
	ret = sh_loop();
	ft_freearr(ft_environ(NULL));
	return (ret);
}
