/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_sys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:04:24 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/16 10:22:59 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_SYS_H
# define EXP_SYS_H
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define FILE_ERR 1
# define FOMT_ERR 2
# define USAGE_ERR 3

typedef	struct		s_shunt
{
	int		op;
	int		ch;
	int		op_len;

	char	*stack;
	//char	*stack;
	char	*queue;
	char	**polish;
	char	**data;
}					t_shunt;

int					get_exp(t_shunt *shnt);
int					get_rules(const int fd);
int					find_query();

char				**express(t_shunt *shnt);

void				tokens(t_shunt *shnt);
void				get_data(int fd, char *file, t_shunt *shnt);
/* all void funcs */
void	get_err(int err_num);
void	tokens(t_shunt *shnt);
void	get_data(int fd, char *file, t_shunt *shnt);

#endif
