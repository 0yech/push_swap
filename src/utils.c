#include "push_swap.h"

long	ft_longatoi(const char *str)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	validintsize(char *s)
{
	long int	nb;

	nb = ft_longatoi(s);
	if (nb > MAX_INT || nb < MIN_INT)
		return (0);
	return (1);
}

int	lookfornums(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i + 1] == '\0')
			return (0);
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (!validintsize(s))
		return (0);
	return (1);
}

int stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*last_stack(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}