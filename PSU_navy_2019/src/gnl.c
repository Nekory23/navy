/*
** EPITECH PROJECT, 2020
** navy
** File description:
** gnl
*/

#include "navy.h"

char *gnl(void)
{
    long unsigned size = 3;
    char *buff = malloc(sizeof(char) * size + 1);

    my_putstr("attack: ");
    if (getline(&buff, &size, stdin) == EOF)
        return (NULL);
    if (my_strlen(buff) != 3) {
        free(buff);
        my_putstr("wrong position\n");
        gnl();
    }
    if (buff[0] < 'A' || buff[0] > 'H' || buff[1] < '1' || buff[1] > '8') {
        free(buff);
        my_putstr("wrong position\n");
        gnl();
    }
    return (buff);
}
