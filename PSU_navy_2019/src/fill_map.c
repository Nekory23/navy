/*
** EPITECH PROJECT, 2020
** navy
** File description:
** fill map
*/

#include "navy.h"

char **fill_first_line(char **map)
{
    char letter = 'A';

    for (int i = 0; i != 17; i++) {
        if (i == 2)
            i++;
        map[0][i] = ' ';
    }
    map[0][1] = '|';
    for (int i = 2; i != 17; i++) {
        if (i % 2 == 0) {
            map[0][i] = letter;
            letter++;
        }
    }
    map[0][17] = '\0';
    return (map);
}

char **fill_nbr(char **map)
{
    char number = '1';

    for (int i = 2; i != 10; i++, number++)
        map[i][0] = number;
    return (map);
}

char **fill_empty_map(char **map)
{
    map = malloc(sizeof(char *) * 10);
    for (int i = 0; i != 10; i++)
        map[i] = malloc(sizeof(char) + 17);
    map = fill_first_line(map);
    map = fill_nbr(map);
    for (int i = 2; i != 10; i++)
        map[i][1] = '|';
    for (int i = 0; i != 17; i++) {
        map[1][i] = '-';
        if (i == 1)
            map[1][i] = '+';
    }
    for (int i = 2; i != 10; i++)
        for (int j = 2; j != 17; j++) {
            if (j % 2 == 0)
                map[i][j] = '.';
            else
                map[i][j] = ' ';
        }
    return (map);
}
