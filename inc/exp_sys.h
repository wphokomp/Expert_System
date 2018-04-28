#ifndef EXP_SYS_H
#   define EXP_SYS_H
#   include <fcntl.h>
#   include "../libft/libft.h"
#   include <stdio.h>
#   include <stdlib.h>
#   include <stdbool.h>

#   define USAGE_ERROR 3
#   define FORMAT_ERROR 2
#   define FILE_ERROR 1

typedef struct  s_shunting
{
    char    **data;
    char    **expressions;
    char    **revExpressions;
    char    **facts;
    char    **queries;

    char    *queue;
    char    *stack;

}               t_shunting;

void    getData(int fd, char *fileName, t_shunting *shunting);
void    getExpressions(t_shunting *shunting);
void    getError(int error);
void    getQueries(t_shunting *shunting);
void    polishNotation(t_shunting *shunting);

#endif