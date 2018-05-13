#include "../inc/exp_sys.h"

void    getQueries(t_shunting *shunting) {
    int     i;
    int     counter;
    
    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '?')
            counter++;
    }
    if (!(shunting->queries = ft_strnew_point(counter))) return;
    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '?')
            shunting->queries[++counter] = ft_strdup(shunting->data[i]);
    }
}

int     main(int argc, char **argv) {
    t_shunting  shunting;
    int         fd;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd > 0) {
            getData(fd, argv[1], &shunting);
            getExpressions(shunting.data);
        }
        else
            getError(FILE_ERROR);
    }
    else {
        getError(USAGE_ERROR);
        exit(1);
    }
    return (0);
}