/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_sys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:04:24 by lmucassi          #+#    #+#             */
/*   Updated: 2018/03/09 19:06:55 by wphokomp         ###   ########.fr       */
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
	int		que;
	int		st;
	int		st_len;
	int		ch;

	char	*stack;
	char	**right;
	char	*no_dups;

	char	*queue;
	char	**polish;
	char	**data;
	char	*query;
	char	**facts;

	bool	**ch_val;
	bool	A;
	bool	B;
}					t_shunt;

bool			compute(bool a, bool b, char op, int *call);

int				get_exp(t_shunt *shnt, char **data);
int				get_rules(const int fd);
int				find_query();
int				op_indx(char *op);
int				change_impl(t_shunt *shnt, int fact, int indx, bool res);

char			**ft_getfacts(t_shunt *shnt);

void			ft_getquery(t_shunt *shnt);
void			get_right(t_shunt *shnt);
void			tokens(t_shunt *shnt);
void			get_data(int fd, char *file, t_shunt *shnt);
void			get_polish(t_shunt *shnt, char **data);
void			get_err(int err_num);
void			get_data(int fd, char *file, t_shunt *shnt);
void			do_brack(t_shunt *shnt, char c);
void			store_val(t_shunt *shnt);

void			init(t_shunt *shnt, int i);
void			is_dup(t_shunt *shnt);
void			process(t_shunt *shnt);
void			push_into(t_shunt *shnt, int i);
void			autonom(t_shunt *shnt);

#endif
