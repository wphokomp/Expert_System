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

# define NO_OF_CHARS 256

typedef struct  s_shunting
{
    char    **data;
    char    **_expression;
    char    **facts;
    char    *operands;
    char    **queries;
    bool    **booleanVal;
    int     factIndx;
    char    *rightOp;

}               t_shunting;

struct Stack
{
    int top;
    unsigned capacity;
    char *array;
    bool *boolArr;
};

struct Stack *createStack(unsigned cap);
struct Stack *createBoolStack(unsigned cap);
int isFull(struct Stack* stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, char item);
char pop(struct Stack *stack);
void pushBool(struct Stack *stack, bool item);
bool popBool(struct Stack *stack);
char lastItem(struct Stack *stack);

void getRightOp(char **data, t_shunting *shunting);
void removeDupli(char *ch, t_shunting *shunting);

void    separate(struct Stack *queue, t_shunting *shunting, char *data);
void getValues(char **data, t_shunting *shunting);
void getFacts(t_shunting *shunting);
void getData(int fd, char *fileName, t_shunting *shunting);
void getExpressions(char **data, t_shunting *shunting);
void getError(int error);
void getQueries(t_shunting *shunting);
void polishNotation(t_shunting *shunting);

#endif
