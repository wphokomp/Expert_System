#include "../inc/exp_sys.h"

int     getNumberOfValidData(const int fd) {
    int     number;
    char    *line;

    number = 0;
    while (get_next_line(fd, &line) == 1) {
        if(line[0] != '#')
            ++number;
    }
    if (number == 0) getError(0);
    return (number);
}

void    getData(int fd, char *fileName, t_shunting *shunting)
{
    char    *line;
    char    *tmp;
    int     counter;

    if (!(shunting->data = ft_listnew(getNumberOfValidData(fd))))
        return ;
    fd = ft_restart_file(fd, fileName);
    counter = 0;
    while (get_next_line(fd, &line) == 1) {
        tmp = ft_strreplace(ft_strtrim(line));
        free(line);
        if (tmp[0] != '#' && ft_strlen(tmp) > 0) {
            line = ft_strsub(tmp, 0, ft_strchr_indx(tmp, '#'));
            free(tmp);
            shunting->data[counter] = ft_strdup(line);
            counter++;
        }
    }
}

int     getNumberOfExpressions(t_shunting *shunting) {
    int     i;

    i = -1;
    while (shunting->data[++i][0] != '=');
    return (i);
}

void    getFacts(t_shunting *shunting) {
    int     i;
    int     counter;

    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '=') {
            //Add error handling
            shunting->facts[++counter] = ft_strdup(shunting->data[i] + 1);
        }
    }
    i = -1;
    counter = 0;
    while (shunting->data[++i])
       if (shunting->data[i][0] == '?') ++counter;
    if (!(shunting->queries = ft_strnew_point(counter)))
        getError(0);
}

void    getExpressions(t_shunting *shunting) {
    int     i;
    int     c;
    int     counter;

    c = 0;
    i = -1;
    //SEGFAULT ON TEST 5
    if (!(shunting->expressions = ft_strnew_point(i)))
        return ;
    while (shunting->data[++i][0] != '=') {
        counter = -1;
        while (shunting->data[i][++counter] != '<' && 
            shunting->data[i][counter] != '=');
        if (!(shunting->expressions[i] = ft_strnew(counter)))
            getError(0);
        else
            shunting->expressions[i] = ft_str_chr(shunting->data[i], '=');
    }
    counter = 0;
    while (shunting->data[++i][0] != '?') ++counter;
    if (!(shunting->facts = ft_strnew_point(++counter)))
        getError(0);
    else
        getFacts(shunting);
}