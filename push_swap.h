/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:51:16 by heahn             #+#    #+#             */
/*   Updated: 2021/12/19 23:51:35 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

char	**argv_parser(int argc, char **argv);
void	duplication_check(int argc, int *argv);
int		ft_strcmp(const char *s1, const char *s2);
static int	ft_integer_check(const char *str);

typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;

	int				max_flag;
	int				flag;
}					t_stack;

typedef struct s_all
{
	t_stack			*stack;
	t_stack			*last;
}					t_all;

void	stack_init(t_stack **lst, int len, int *arguments);
int		stack_len(t_stack *a);

#endif