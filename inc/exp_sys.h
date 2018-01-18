/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_sys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:04:24 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/18 15:35:53 by wphokomp         ###   ########.fr       */
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

	char	*stack;
	char	**right;
	char	*no_dups;

	char	*queue;
	char	**polish;
	char	**data;
	char	*query;
}					t_shunt;

int					get_exp(t_shunt *shnt);
int					get_rules(const int fd);
int					find_query();

char				**express(t_shunt *shnt);

void				get_right(t_shunt *shnt);
void				tokens(t_shunt *shnt);
void				get_data(int fd, char *file, t_shunt *shnt);
void				get_polish(t_shunt *shnt);
void				get_err(int err_num);
void				get_data(int fd, char *file, t_shunt *shnt);
void				do_brack(t_shunt *shnt, char c);

void				init(t_shunt *shnt, int i);
void				is_dup(t_shunt *shnt);
void				push_into(t_shunt *shnt, int i);

#endif
