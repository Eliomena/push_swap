#include "push_swap.h"

void	ft_error(int *stack)
{
	free(stack);
	ft_printf("Error\n");
	exit (1);
}

int		ft_argv_atoi(char *str, int *stack)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		ft_error(stack);
	return (num * neg);
}

int		ft_argv_strlen(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

int		ft_check_repeat(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
			{
				ft_error(stack);
				return (TRUE);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (FALSE);
}

int		ft_check_sorted(int *stack, int size)
{
	int i;
	i = 1;
	while (i < size)
	{
		if (stack[i - 1] > stack[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}