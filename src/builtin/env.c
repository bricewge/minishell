/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	b_env_display(char **args, char **envp)
{
	int		i;

	if (!envp)
		envp = ft_environ(NULL);
	i = 0;
	if (args[1] == 0)
		while (envp[i])
			ft_putendl(envp[i++]);
	return (0);
}

int			b_env(char **args)
{
	int		i;
	int		exact;
	char	**envp;

	i = 0;
	exact = 0;
	if (ft_strequ(args[1], "-i"))
	{
		exact = 1;
		++i;
	}
	envp = NULL;
	if (exact)
	{
		b_env_display(&args[i], envp);
	}
	else
		b_env_display(&args[i], NULL);
	return (0);
}
