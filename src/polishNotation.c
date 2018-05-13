#include "../inc/exp_sys.h"

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
    // values = getValues(queue);
    while (ft_isalpha(token = pop(queue)) || op(token)) {
         ft_putchar(token);
     }
    ft_putchar('\n');
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
<<<<<<< HEAD
    // i = -1;
    // while (shunting->_expression[++i]) {
    //     ft_putendl(shunting->_expression[i]);
    // }
}

char    *getBoolValues(char **data) {
  int   i;
  char *noDup = (char *) malloc(10 * sizeof (char));
  if (noDup == NULL) {
      /* Memory could not be allocated, the program should
         handle the error here as appropriate. */
  } else {
      /* Allocation succeeded.  Do something.  */

        i = -1;
        // shunting->_expression = ft_strnew_point(ft_strlen_point(data));
        while (data[++i]) {
          // j = -1;
          if (data[i][0] != '=') {
              if (data[i][0] != '?'){
                  // shunting->_expression[++j] = ft_strnew(ft_strlen(data[i]));
                  
              }
          }
      }

      free(noDup);  /* We are done with the int objects, and
                     free the associated pointer. */
      noDup = NULL; /* The pointed-to-data  must not be used again,
                     unless re-assigned by using malloc
                     again. */
  }
  // int     j;

  return noDupl;
}
=======
}
>>>>>>> 45007735a6600b3b6e97514b816926c8f26659ea
