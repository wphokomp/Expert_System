#ifndef EXP_SYS_H
#   define EXP_SYS_H
#   include <fcntl.h>
#   include "../libft/libft.h"
#   include <stdio.h>
#   include <stdlib.h>
#   include <limits.h>
#   include <stdbool.h>

#   define USAGE_ERROR 3
#   define FORMAT_ERROR 2
#   define FILE_ERROR 1

typedef struct  s_shunting
{
    char    **data;
    char    **_expression;
    char    **revExpressions;
    char    **facts;
    char    **queries;

}               t_shunting;

struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

struct Stack *createStack(unsigned cap);
struct Stack **create2DStack(unsigned cap);
int isFull(struct Stack* stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, char item);
char pop(struct Stack *stack);
char lastItem(struct Stack *stack);

struct Stack *getValues(struct Stack *queue);
void getFacts(char **data);
void getData(int fd, char *fileName, t_shunting *shunting);
void getExpressions(char **data);
void getError(int error);
void getQueries(t_shunting *shunting);
void polishNotation(t_shunting *shunting);

#endif
