#include "push_swap.h"

int is_sorted(int *nums, int totalnums)
{
	int	i;

	i = 0;
	while (i < totalnums - 1)
	{
		if (nums[i] > nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}