/*
** EPITECH PROJECT, 2020
** navy
** File description:
** error_handling
*/

#include "navy.h"

int error_handling_player1(char *path)
{
    char **pos = open_file(path);

    if (pos == NULL)
        return (ERROR);
    if (check_pos(pos) == ERROR) {
        free(pos);
        return (ERROR);
    }
    free(pos);
    return (SUCCESS);
}

int error_handling_player2(char *path)
{
    char **pos = open_file(path);

    if (pos == NULL)
        return (ERROR);
    if (check_pos(pos) == ERROR) {
        free(pos);
        return (ERROR);
    }
    free(pos);
    return (SUCCESS);
}

int error_handling(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        write_error(STR_ERROR_ARG);
        return (ERROR);
    }
    if (ac == 2)
        if (error_handling_player1(av[1]) == ERROR)
            return (ERROR);
    if (ac == 3)
        if (error_handling_player2(av[2]) == ERROR)
            return (ERROR);
    return (SUCCESS);
}
