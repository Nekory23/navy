/*
** EPITECH PROJECT, 2020
** navy
** File description:
** split all the positions
*/

#include "navy.h"

char **split_pos(char *buffer)
{
    char **pos = malloc(sizeof(char *) * 4);

    for (int i = 0; i != 4; i++)
        pos[i] = malloc(sizeof(char) * READ_SIZE);
    for (int i = 0, j = 0, z = 0; buffer[i] != '\0'; i++, z++) {
        if (buffer[i] == '\n') {
            i++;
            j++;
            z = 0;
        }
        if (j == 4)
            break;
        pos[j][z] = buffer[i];
    }
    return (pos);
}
