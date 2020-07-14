/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game2
*/

#include "navy.h"

player_t *p;

static void reset_value(void)
{
    p->count = 0;
    p->x = 0;
    p->y = 0;
}

int game2(map_t *m)
{
    reset_value();
    my_putstr("waiting for enemy's attack...\n");
    if (multi_receive() == ERROR)
        return (TRUE);
    p->attack = check_co_map(m->map);
    print_attack();
    usleep(1000);
    send_answer(p->attack);
    map_update(m);
    usleep(1000);
    if ((p->str = gnl()) == NULL)
        return (quit_game());
    multi_kill(catoi1(p->str[0]), catoi(p->str[1]) + 1);
    p->attack = 0;
    receive_answer();
    map_update_e(m, catoi1(p->str[0]), catoi(p->str[1]) + 1);
    usleep(1000);
    if (win_check(m->map_e) == TRUE)
        return (TRUE);
    display_all(m->map, m->map_e);
    return (FALSE);
}
