/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:51:34 by heahn             #+#    #+#             */
/*   Updated: 2022/01/17 07:51:44 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	result(int min, unsigned long long	sum)
{
	if (min == -1 && sum > 2147483648)
		return (0);
	else if (min == 1 && sum >= 2147483648)
		return (0);
	else
		return ((int)sum * min);
}

int	ft_atoi(char *str)
{
	int					min;
	unsigned long long	sum;

	min = 1;
	sum = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min = min * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10;
		sum = sum + *str - 48;
		str++;
	}
	return (result(min, sum));
}


int	integer_check(int argc, char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if(!(ft_atoi(argv[i])))
			return(0);
		i++;
	}
	return (1);
}


bool	duplicate_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = i - 1;
		while (j > 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (false);
			j--;
		}
		i++;
	}
	return (true);
}


void	argument_check(int argc, char **argv)
{
	//if (argc < 2)
	if(argc == 1)
		ft_error("error : num of arguments", 24);
	if(!integer_check(argc, argv))
		ft_error("error : num of argc", 19);
	if(!duplicate_check(argc, argv))
		ft_error("error : duplicate arguments", 27);	



}
