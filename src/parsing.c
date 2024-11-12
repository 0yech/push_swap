#include "push_swap.h"

int	parsecheck(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!checkvalidity(argv[1]))
			return (0);
	}
	else
	{
		if (!checkargs(argv))
			return (0);
	}
	return (1);
}

int	checkargs(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (!lookfornums(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checkvalidity(char *s)
{
	char	**p;
	int		i;

	i = 0;
	p = ft_split(s, ' ');
	if (!p)
		return (0);
	while (p[i])
	{
		if (!lookfornums(p[i]))
		{
			free_data(p);
			return (0);
		}
		i++;
	}
	free_data(p);
	return (1);
}
