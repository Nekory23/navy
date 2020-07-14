/*
** EPITECH PROJECT, 2020
** navy
** File description:
** open file
*/

#include "navy.h"

char **open_file(char *path)
{
    char *buffer = malloc(sizeof(char) * READ_SIZE + 1);
    int fd = open(path, O_RDONLY);
    int rd = read(fd, buffer, READ_SIZE);
    char **pos;

    if (fd == -1 || rd < 0) {
        write_error(STR_ERROR_OPEN);
        return (NULL);
    }
    if (count_boats(buffer) == ERROR) {
        free(buffer);
        return (NULL);
    }
    buffer = clean_buffer(buffer);
    pos = split_pos(buffer);
    free(buffer);
    return (pos);
}
