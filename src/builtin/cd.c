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

#include <sys/param.h>
#include "minishell.h"

int				b_cd(char **args)
{
	char		*newpwd;
	char		*oldpwd;
	char		tmp[PATH_MAX];

	if ((oldpwd = ft_getenv("PWD")) == NULL)
		oldpwd = getcwd(ft_strnew(PATH_MAX), PATH_MAX);
	//
	if (args[1] == NULL || !args[1][0])
		newpwd = ft_getenv("HOME");
	else if (ft_strequ(args[1], "-"))
		ft_putendl(newpwd = ft_getenv("OLDPWD"));
	else
		newpwd = args[1];
	newpwd = realpath(newpwd, tmp);
	if (newpwd == NULL)
		return (ft_puterror("invalid directory: ", NULL, 1));
	if (chdir(newpwd) != 0)
		return (ft_puterror("invalid directory: ", newpwd, 1));
	// if error free(oldpwd) and print erro message
	ft_setenv("OLDPWD", oldpwd, 1);
	ft_setenv("PWD", newpwd, 1);
	return (0);
}
