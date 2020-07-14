/*
** EPITECH PROJECT, 2020
** navy
** File description:
** clean the read buffer
*/

#include "navy.h"

int count_boats(char *buffer)
{
    int n = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            n++;
    if (n != 4) {
        write_error(STR_ERROR_NBR);
        return (ERROR);
    }
    return (SUCCESS);
}

char *clean_buffer(char *buffer)
{
    int n = 4;
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count++;
        if (count == 4) {
            buffer[i + 1] = '\0';
            break;
        }
    }
    return (buffer);
}
