/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				b_cd(char **args)
{
	char		*curpath;

	curpath = NULL;
	if (!args[1] || !args[1][0])
		curpath = ft_getenv("HOME");
	else if (ft_strequ(args[1], "-"))
	{
		curpath = ft_getenv("OLDPWD");
		ft_putendl(curpath);
	}
	else
		curpath = args[1];
	if (chdir(curpath) != 0)
		return (ft_puterror("invalid directory: ", curpath, 1));
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	ft_setenv("PWD", curpath, 1);
	return (0);
}
