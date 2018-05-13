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

void getFacts(t_shunting *shunting) {
    int i;
    int counter;

    i = -1;
    counter = 0;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '=') {
            ++counter;
        }
    }
    shunting->facts = ft_strnew_point(counter);
    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '=') {
            shunting->facts[++counter] = ft_strdup(shunting->data[i] + 1);
        }
    }
}