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

t_bltin			g_bltins[8] = {
	{b_echo, 6, "echo"},
	{b_cd, 4, "cd"},
	{b_setenv, 8, "setenv"},
	{b_unsetenv, 10, "unsetenv"},
	{b_env, 7, "env"},
	{b_exit, 6, "exit"},
	{b_true, 4, "true"},
	{b_false, 5, "false"}
};

void			ft_freearr(char **pstr)
{
	int			i;

	i = -1;
	while (pstr[++i])
		free(pstr[i]);
	free(pstr);
}

int				sh_loop(void)
{
	int			status;
	char		*line;
	char		**args;

	status = 0;
	while (status >= 0)
	{
		ft_putstr(PROMPT);
		get_next_line(0, &line);
		args = sh_parse(line);
		status = sh_exec(args);
		free(line);
		ft_freearr(args);
	}
	return (status < 0 ? 0 : status);
}

int				main(int ac, char **av)
{
	if (ac && *av)
		return (sh_loop());
	return (0);
}
