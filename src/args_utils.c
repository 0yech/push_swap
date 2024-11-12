#include "push_swap.h"

int	splitcount(char *arg)
{
	int		count;
	char	**split;
	int		i;

	count = 0;
	i = 0;
	if (!arg || !*arg)
		return (0);
	if (ft_strchr(arg, ' '))
	{
		split = ft_split(arg, ' ');
		if (!split)
			return (0);
		while (split[i])
		{
			count++;
			free(split[i++]);
		}
		free(split);
	}
	else
		count++;
	return (count);
}

int	countargs(char **argv)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (argv[i])
	{
		count += splitcount(argv[i]);
		i++;
	}
	return (count);
}

int	process_argument(char *arg, int *nums, int *k)
{
	if (ft_strchr(arg, ' '))
		return (process_split_argument(arg, nums, k));
	else
		return (process_single_argument(arg, nums, k));
}

int	process_single_argument(char *arg, int *nums, int *k)
{
	if (!lookfornums(arg))
		return (0);
	nums[(*k)++] = (int)ft_longatoi(arg);
	return (1);
}

int	process_split_argument(char *arg, int *nums, int *k)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!lookfornums(split[j]))
		{
			free_data(split);
			return (0);
		}
		nums[(*k)++] = (int)ft_longatoi(split[j++]);
	}
	free_data(split);
	return (1);
}
