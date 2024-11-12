#include "push_swap.h"

int	valid_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!parsecheck(argc, argv))
		return (0);
	return (1);
}
