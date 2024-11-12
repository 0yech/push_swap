#include "push_swap.h"

int	has_duplicates(int *nums, int totalnums)
{
	int	i;
	int	j;

	i = 0;
	while (i < totalnums - 1)
	{
		j = i + 1;
		while (j < totalnums)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
