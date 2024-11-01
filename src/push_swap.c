/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:28:43 by cheyo             #+#    #+#             */
/*   Updated: 2024/11/01 20:30:30 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

long int	ft_longatoi(const char *str)
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

int		validintsize(char *s)
{
	long int	nb;

	nb = ft_longatoi(s);

	if (nb > MAX_INT || nb < MIN_INT)
		return (0);
	return (1);
}

int		lookfornums(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
		if (ft_isdigit(s[i++]) != 1)
			return (0);
	if (validintsize(s) != 1)
		return (0);
	return (1);
}

int		checkargs(char *args[])
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (lookfornums(args[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	free_data(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

int	checkvalidity(char *s)
{
	char	**p;
	int 	i;
	
	i = 0;
	p = ft_split(s, 32);
	if (p == NULL)
		return (0);
	while (p[i])
	{
		if(lookfornums(p[i++]) != 1)
			return (0);
	}
	free_data(p);
	p = NULL;
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("No args");
		return (0);
	}
	if (argc == 2)
	{
		if (checkvalidity(argv[1]) != 1)
		{
			ft_printf("Invalid String");
			return (0);
		}
	}
	if (argc > 2)
	{
		if (checkargs(argv) != 1)
		{
			ft_printf("Invalid args");
			return (0);
		}
	}
	ft_printf("valid !");
	return (1);

	/*
		TODO

		Move all checks to an error handler to save space.

		! CHECK FOR DUPLICATES !

		(Make an array of int and compare numbers)
	*/
}

/*
   ----------------
	PUSH_SWAP MEMO
   ----------------

	! If you're learning from this, make sure to read the subject beforehand.

	2 Piles of data,

	x	
	y
	z
	_	_
	a	b

	^---^
	"a" contains data, "b" is empty but data can be pushed to it from "a".

	Goals

	- Sort the "a" pile.
	- Only using "pushswap" language, display every instruction to sort the pile.
	- Show "Error" on the std error output if needed.
		the write function (from unistd.h) has 3 types for its first argument

			write(0, x, x) -> 0 means input. to type something in. (not used)
			write(1, x, x) -> 1 means output. to print out something.
			write(2, x, x) -> 2 means Error. to print errors specifically.

	- Try to use the least amount of instructions when solving !
	- Use and learn different solve algorithms. You will use different
		algorithms depending on the amounts of arguments. (Google's the friend)

	Think about it. A solve with very small amount of arguments will probably
	take less time with a simple algorithm.

	Examples :
		
	./push_swap 2 1 3 6 5 8
	sa
	pb
	pb
	pb
	sa
	pa
	pa
	pa

	OR

	./push_swap "2 1 3 6 5 8" (Yes, careful ! You must check for single args.)
	sa
	pb
	pb
	pb
	sa
	pa
	pa
	pa
	
	==================
	PUSH SWAP LANGUAGE
	==================
	
	sa (swap a) 	-> swaps the two elements on the top of the pile.
	sb (swap b)		-> ^same but with b.
	ss				-> does sa and sb at the same time.

	pa (push a) 	-> takes the top element of b to put it on a.
	pb (push b)		-> ^same but piles are reversed.

	ra (rotate a)	-> the pile goes up one spot. and the top one becomes last.
	rb (rotate b)	-> ^same with pile b.
	rr				-> does ra and rb at the same time.

	rra (reverserot)-> rotates but goes down one spot, lowest become the top one.
	rrb (reverserot)-> ^same but with b
	rrr				-> does rra and rrb at the same time.

	===================
	  TIPS TO ACHIEVE
	===================

	/!\ You are allowed to use libft & your version of printf.

	Import them, have a makefile with an empty project with a main function,
	and make sure you are able to use your tools within your project correctly.

	The push_swap program comes with a checker program, this program is a tester.
	You can use it to check if your stuff runs correctly. You can also mix it
	with shell commands to make your own test battery.

	First thing your program should check is if the arguments sent are correct.

	When calling the push_swap program, you can get the arguments in two ways.

	./push_swap 2 3 1 6 9 5
	./push_swap "2 3 1 6 9 5"

	the second case should require you to split your arguments.

	An approach i would take is to check early if the args only contain nums.
	As mentionned on the subject, nums can be negative, but none of them can
	be duplicates. Checking the arguments early will let you catch errors if
	duplicate numbers are present.
*/