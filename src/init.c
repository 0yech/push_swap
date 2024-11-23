/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:44:57 by nrey              #+#    #+#             */
/*   Updated: 2024/11/23 11:45:01 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_nums(char **argv, int **nums, int *totalnums)
{
	*totalnums = get_total_nums(argv + 1);
	if (*totalnums == 0)
		return (0);
	if (!allocate_nums(nums, *totalnums))
		return (0);
	if (!fill_nums(argv + 1, *nums))
	{
		free(*nums);
		*nums = NULL;
		return (0);
	}
	if (has_duplicates(*nums, *totalnums))
	{
		free(*nums);
		*nums = NULL;
		return (0);
	}
	return (1);
}
