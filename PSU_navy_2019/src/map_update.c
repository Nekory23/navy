/*
** EPITECH PROJECT, 2020
** navy
** File description:
** map_update.c
*/

#include "navy.h"

player_t *p;

int check_co_map(char **map)
{
    if (map[p->y][p->x] != '.' && map[p->y][p->x] != 'o')
        return (1);
    if (map[p->y][p->x] == '.' || map[p->y][p->x] == 'o')
        return (2);
}

void map_update_e(map_t *m, int x, int y)
{
    if (p->attack == 1) {
        m->map_e[y][x] = 'x';
        my_putchar(p->str[0]);
        my_putchar(p->str[1]);
        my_putstr(": hit\n\n");
    }
    if (p->attack == 2) {
        m->map_e[y][x] = 'o';
        my_putchar(p->str[0]);
        my_putchar(p->str[1]);
        my_putstr(": missed\n\n");
    }
}

void map_update(map_t *m)
{
    if (p->attack == 1)
        m->map[p->y][p->x] = 'x';
    if (p->attack == 2)
        m->map[p->y][p->x] = 'o';
}
