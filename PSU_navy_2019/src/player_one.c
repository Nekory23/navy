/*
** EPITECH PROJECT, 2020
** navy
** File description:
** player_one
*/

#include "navy.h"

player_t *p;

int player_one(map_t *m)
{
    p->turn = 1;
    p->pid = getpid();
    my_putstr("my_pid:  ");
    my_put_nbr(p->pid);
    my_putstr("\nwaiting for enemy connection...\n");
    connect();
    my_putstr("\nenemy connected\n\n");
    m->map_e = fill_empty_map(m->map_e);
    display_all(m->map, m->map_e);
    while (game1(m) != TRUE);
    if (p->check_eof == 1)
        return (SUCCESS);
    display_all(m->map, m->map_e);
    if (count_hit(m->map_e) == 14) {
        my_putstr("I won\n");
        return (0);
    }
    else {
        my_putstr("Enemy won\n");
        return (1);
    }
}
