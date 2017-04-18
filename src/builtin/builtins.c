#include "minishell.h"

int			b_echo(char **args)
{
	int		i;

	i = 0;
	while (args[++i])
	{
		if (i > 1)
			ft_putchar(' ');
		ft_putstr(args[i]);
	}
	ft_putchar('\n');
	return (0);
};

int			b_setenv(char **args)
{
	int		ret;

	if (!args[1])
		return (1);
	if (args[2])
		ret = ft_setenv(args[1], args[2], 1);
	else
		ret = ft_setenv(args[1], "", 2);
	return (ft_abs(ret));
};

int			b_unsetenv(char **args)
{
	int		ret;

	if (!args[1])
		return (1);
	ret = ft_unsetenv(args[1]);
	return (ft_abs(ret));
};
