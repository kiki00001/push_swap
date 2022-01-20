/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 04:36:44 by heahn             #+#    #+#             */
/*   Updated: 2021/11/02 05:05:24 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd > 0)
	{
		write(fd, s, sizeof(char) * ft_strlen(s));
		write(fd, "\n", 1);
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = '\0';
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && size != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}

// ' ' 공백의 수 카운트  리턴값= ' ' + 1
static int		str_size(const char *str, char c)
{
	size_t	size;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (flag && *str != c)  //flag가 1 이고 str=' ' 아니면 
		{
			size++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	return (size);
}

char	**ft_free(char **tmp, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
		free(tmp[i++]);
	free(tmp);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (str_size(s, c) + 1) + 1)))
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue;
		}
		tmp = (char *)s;
		while (*s && *s != c)
			s++;
		if (!(ret[i] = (char *)malloc(s - tmp + 1)))
			return (ft_free(ret, i));
		ft_strlcpy(ret[i++], tmp, s - tmp + 1);
	}
	ret[i] = 0;
	return (ret);
}

static int	str_parser(int argc, char **argv)
{
	int		result;
	char	**temp;
	int		i;

	result = 0;
	while (argc-- > 1)
	{
		i = 0;
		temp = ft_split(*(++argv), ' ');
		if (!temp)
			exit(EXIT_FAILURE);
		while (temp[i] != 0)
		{
			result++;
			free(temp[i]);
			i++;
		}
		free(temp);
	}
	return (result);
}

char	**argv_parser(int argc, char **argv)
{
	char	**arg;
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arg = (char **)malloc(sizeof(char *) * (str_parser(argc, argv) + 1));
	if (!arg)
		ft_error();
	while (argc-- > 1)
	{
		i = 0;
		temp = ft_split(*(++argv), ' ');
		if (!temp)
			ft_error();
		while (temp[i] != 0)
			arg[j++] = temp[i++];
		free(temp);
	}
	arg[j] = 0;
	return (arg);
}

static int	ft_integer_check(const char *str)
{
	int		i;
	ssize_t	result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] == 0)
		ft_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		result = (result * 10) + str[i] - '0';
		i++;
	}
	result *= sign;
	if (ft_strlen(str) > 11 || result > 2147483647 || result < -2147483648)
		ft_error();
	return ((int)result);
}

void	duplication_check(int len, int *num)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] == num[j])
				ft_error();
			j++;
		}
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if ((s1[i] != s2[i]) || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
}
//스택 길이
int	stack_len(t_stack *a)
{
	int		i;
	int		start;
	t_stack	*ptr;

	if (!a)
		return (0);
	i = 1;
	ptr = a;
	start = ptr->data;
	while (ptr->next->data != start)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

static t_stack	*add_element(int data)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		ft_error();
	temp->data = data;
	temp->flag = 0;
	temp->max_flag = 0;
	temp->prev = temp;
	temp->next = temp;
	return (temp);
}

void	stack_init(t_stack **a, int len, int *arg)
{
	t_stack	*new;

	*a = add_element(arg[len - 1]);
	while (len > 1)
	{
		new = add_element(arg[len - 2]);
		new->next = *a;
		new->prev = (*a)->prev;
		(*a)->prev->next = new;
		(*a)->prev = new;
		(*a) = new;
		len--;
	}
}

int	ft_int_check_return_len(int **result, char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != 0)
		i++;
	*result = (int *)malloc(sizeof(int) * i);
	while (arg[j] != 0)
	{
		(*result)[j] = ft_integer_check(arg[j]);
		//printf("result : %d\n" , (*result)[k++]);
        free(arg[j]);
		j++;
	}
	free(arg[j]);
	free(arg);
	arg = 0;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		len;
	int		*num;
	char	**arg;

	a = 0;
	arg = argv_parser(argc, argv);    //arguments에 인수로 받은 각 값을 넣음
/*
    int i =0;
    while(arg[i])
    {   
        printf(" : %s \n", arg[i]);
        i++;
    }
*/
	len = ft_int_check_return_len(&num, arg);      //integer인지, int 범위인지 체크하고 갯수 받아옴, num에는int형 인자 argument에는 char형 인자
	duplication_check(len, num);            
	stack_init(&a, len, num);
	//stack_sort(&a, len);
	return (0);
}
