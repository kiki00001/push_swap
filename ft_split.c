/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 08:26:53 by heahn             #+#    #+#             */
/*   Updated: 2022/01/16 08:26:55 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


//size_t	count_words(char const *s, char c)
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



/*
char			**ft_split(char const *s, char c)
{
	char	**result;
	int		idx;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char*) * (str_size(s, c) + 1));
	if (!result)
		exit(1);
	idx = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			result[idx] = get_str_split(s, c);
			if (!result[idx++])
				return (go_free_split(result));
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[idx] = 0;
	return (result);
}
*/

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

integer_check(int argc, char ** argv)
{
    int		size;
	int		i;
    int		tmp_i;
	char	**tmp;

    size = 0;
	i = 1;

    while (i < argc)
		size += str_size(argv[i++], ' ');


}