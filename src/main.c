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

void booleanValue(t_shunting *shunting) {
    int i;
    int k;
    int l;
    bool **boolVal;

    i = -1;
    boolVal = (bool **) malloc(ft_strlen_point(shunting->facts) * sizeof(bool));
    while (shunting->facts[++i]) {
        k = -1;
        l = -1;
        boolVal[i] = (bool *)malloc(ft_strlen(shunting->operands) * sizeof(bool));
        while (shunting->operands[++k]) {
            if (shunting->facts[i][+l] == shunting->operands[k]) {
                boolVal[i][k] = true;
            } else {
                boolVal[i][k] = false;
            }
        }
    }
    k = 0;
    i = 0;
    while (boolVal[k][i] != '\0') {
        while (boolVal[k][i] != '\0') {
            ft_putnbr(boolVal[k][i]);
            i++;
        }
        k++;
    }
}

int     main(int argc, char **argv) {
    t_shunting  shunting;
    int         fd;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd > 0) {
            getData(fd, argv[1], &shunting);
            getExpressions(shunting.data, &shunting);
            getFacts(&shunting);
            booleanValue(&shunting);
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