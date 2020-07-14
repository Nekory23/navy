/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game1
*/

#include "navy.h"

player_t *p;

static void reset_value(void)
{
    p->attack = 0;
    p->x = 0;
    p->y = 0;
}

int game1(map_t *m)
{
    reset_value();
    if ((p->str = gnl()) == NULL)
        return (quit_game());
    multi_kill(catoi1(p->str[0]), catoi(p->str[1]) + 1);
    receive_answer();
    usleep(1000);
    map_update_e(m, catoi1(p->str[0]), catoi(p->str[1]) + 1);
    my_putstr("waiting for enemy's attack...\n");
    if (multi_receive() == ERROR)
        return (TRUE);
    p-> count = 0;
    p->attack = check_co_map(m->map);
    print_attack();
    usleep(1000);
    send_answer(p->attack);
    map_update(m);
    usleep(1000);
    if (win_check(m->map_e) == TRUE)
        return (TRUE);
    display_all(m->map, m->map_e);
    return (FALSE);
}
