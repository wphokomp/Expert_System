#include "libft.h"

char    *ft_strreplace(char *str) {
    char    *new_str;
    int     i;
    int     numberOfLetters;

    i = -1;
    numberOfLetters = -1;
    while (str[++i]){
        if (str[i] != ' ')
            numberOfLetters++;
    }
    new_str = ft_strnew(i);
    i = -1;
    numberOfLetters = -1;
    while (str[++i]) {
        if (str[i] != ' ')
            new_str[++numberOfLetters] = str[i];
    }
    return (new_str);
}