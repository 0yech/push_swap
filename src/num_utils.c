#include "push_swap.h"

int	get_total_nums(char **argv)
{
	int	totalnums;

	totalnums = countargs(argv);
	if (totalnums == 0)
		return (0);
	return (totalnums);
}

int	allocate_nums(int **nums, int totalnums)
{
	*nums = malloc(sizeof(int) * totalnums);
	if (!*nums)
		return (0);
	return (1);
}

int	fill_nums(char **argv, int *nums)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (argv[i])
	{
		if (!process_argument(argv[i], nums, &k))
			return (0);
		i++;
	}
	return (1);
}