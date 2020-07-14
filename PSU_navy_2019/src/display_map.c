/*
** EPITECH PROJECT, 2020
** navy
** File description:
** display the maps
*/

#include "navy.h"

void display_all(char **map, char **map_e)
{
    my_putstr("my positions:\n");
    for (int i = 0; i != 10; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; i != 10; i++) {
        my_putstr(map_e[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}
