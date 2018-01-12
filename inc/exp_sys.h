/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_sys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:04:24 by lmucassi          #+#    #+#             */
/*   Updated: 2018/01/12 15:07:57 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_SYS_H
# define EXP_SYS_H
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

/* all structs here */


/* all int funcs */
int			get_rules(const int fd);

/* all char funcs */
char		**get_data(int fd, char *file);

/* all void funcs */


#endif
