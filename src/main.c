#include "../inc/exp_sys.h"

void    getQueries(t_shunting *shunting) {
    int     i;
    int     counter;

    i = -1;
    counter = -1;
    while (shunting->data[++i]) {
        if (shunting->data[i][0] == '?')
            shunting->queries[++counter] = ft_strdup(shunting->data[i] + 1);
    }
}

int     main(int argc, char **argv) {
    t_shunting  shunting;
    int         fd;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd > 0) {
            getData(fd, argv[1], &shunting); //This is fine
            ft_putendl("=");
            getExpressions(&shunting); //This is fine
            shunting.revExpressions = ft_strnew_point(
                ft_strlen_point(shunting.expressions));
            getQueries(&shunting);
            polishNotation(&shunting);            
            int i = -1;
            while (shunting.revExpressions[++i]) ft_putendl(shunting.revExpressions[i]);
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