#include "../inc/exp_sys.h"

char  *removeDups(char *str) {
  bool *bin_hash;
  int ip_ind = 0, res_ind = 0;
  char temp;

  bin_hash = (bool *) malloc(NO_OF_CHARS * sizeof(bool));
  /* In place removal of duplicate characters*/
  while (*(str + ip_ind))
  {
  	temp = *(str + ip_ind);
  	if (bin_hash[temp] == 0)
  	{
  		bin_hash[temp] = 1;
  		*(str + res_ind) = *(str + ip_ind);
  		res_ind++;
  	}
  	ip_ind++;
}
}

char    *getBoolValues(char **data) {
  int   i;
  int   x;
  int   y;
  char *noDup;

  if (!(noDup = (char *) malloc(10 * sizeof (char)))) {
      /* Memory could not be allocated, the program should
         handle the error here as appropriate. */
  } else {
      /* Allocation succeeded.  Do something.  */
        i = -1;
        x = 0;
        y = 0;
        while (data[++i]) {
          // j = -1;
          if (data[i][0] != '=') {
              if (data[i][0] != '?') {
                if (ft_isalpha(data[i][x])) {
                  noDup[y] = data[i][x];
                  y++;
                }
              }
          }
          x++;
      }
  }
  ft_putendl(noDup);
  return removeDups(noDup);
}

void    convertToPostfix(char *data) {
    int i;
    char token;
    // struct Stack *values;
    struct Stack *queue;
    struct Stack *stack;

    i = -1;
    queue = createStack(ft_strlen(data));
    stack = createStack(ft_strlen(data));
    while (data[++i]) {
        if (ft_isalpha(data[i])) {
            push(queue, data[i]);
        } else if (op(data[i])) {
            if (op(lastItem(stack))) {
                if (opPrecedence(lastItem(stack), data[i])) {
                    push(queue, pop(stack));
                }
            }
            push(stack, data[i]);
        } else if (data[i] == '(') {
            push(stack, data[i]);
        } else if (data[i] == ')') {
            while (lastItem(stack) != '(') {
                push(queue, pop(stack));
            }
            pop(stack);
        }
    }
    while (op(token = pop(stack))) { push(queue, token); }
    // // values = getValues(queue);
    // while (ft_isalpha(token = pop(queue)) || op(token)) {
    //      ft_putchar(token);
    //  }
    // ft_putchar('\n');
    getBoolValues(data);
}

void    getExpressions(char **data) {
    int     i;

    i = -1;
    while (data[++i]) {
        if (data[i][0] != '=') {
            if (data[i][0] != '?'){
                convertToPostfix(ft_strsub(data[i], 0, ft_strchr_indx(data[i], '=')));
            }
        }
    }
    // i = -1;
    // while (shunting->_expression[++i]) {
    //     ft_putendl(shunting->_expression[i]);
    // }
}
