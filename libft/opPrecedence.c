#include "libft.h"

int     opPrecedence(char op) {
    int     i;

    i = -1;
    while (OP[++i]) {
        if  (OP[i] == op)
            break ;
    }
    return (i);
}