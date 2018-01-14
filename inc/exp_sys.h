/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_sys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:04:24 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/14 12:52:07 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_SYS_H
# define EXP_SYS_H
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

/* all structs here */

typedef	struct		s_shunt
{
	int		i;
	int		j;

	char	*operands;
	char	*opStack;
	char	*outStack;
	char	**polish;
	char	**data;
}					t_shunt;

/* all int funcs */
int		get_rules(const int fd);
int		find_query();

/* all char funcs */
char	**express(char **data);

/* all void funcs */
void	tokens(t_shunt *shnt);
void	get_data(int fd, char *file, t_shunt *shnt);

#endif
