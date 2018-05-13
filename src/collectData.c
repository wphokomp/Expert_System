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

void getFacts(char **data) {
    int i;

    i = -1;
    while (data[++i]) {
        if (data[i][0] == '=') {
            ft_putendl(data[i]);
        }
    }
}
// struct Stack *getValues(struct Stack *queue) {

// }