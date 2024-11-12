#include "push_swap.h"

int	main(int argc, char **argv)
{
	//t_stack	*a;
	//t_stack	*b;
	int		*nums;
	int		totalnums;

	//a = NULL;
	//b = NULL;
	nums = NULL;
	if (argc < 2)
		return (0);
	if (!init_nums(argv, &nums, &totalnums) || !valid_args(argc, argv))
	{
		ft_printf("Error\n");
		free(nums);
		return (1);
	}
	test_moves(nums, totalnums);
	free(nums);
	return (0);
}

// REMINDERS

// Dereference when willing to get values from a list directly.
// Example in push_move : "(*src)->next" and not "*src->next"
// Because the -> operator has priority over the *.
// This must be done when working with the list itself.
// Like head, src or dst.
// **src does not contain a "next" field, as it's the list itself.
// Dereferencing src let's us access it's node and therefore, fields.


// TODO

// Add cleanup in case nums is initiated but still causes error.
// Cleanup shall free a, b and nums to avoid leaks.