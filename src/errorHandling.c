#include "../inc/exp_sys.h"

void    getError(int error) {
    if (error == 1)
        ft_putendl("File does not exist.");
    else if (error == 2)
        ft_putendl("Format of the file is invalid.");
    else if (error == 3)
        ft_putendl("Usage: ./expert_system [FILE_NAME]");
    else
        ft_putendl("There seems to be an error.");
    exit(0);
}