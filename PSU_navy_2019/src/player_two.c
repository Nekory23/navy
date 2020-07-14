/*
** EPITECH PROJECT, 2020
** navy
** File description:
** player two
*/

#include "navy.h"

player_t *p;

int end_player_two(map_t *m)
{
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

int player_two(char **av, map_t *m)
{
    char **pos = open_file(av[2]);

    p->turn = 0;
    p->pid = getpid();
    p->pid_2 = my_atoi(av[1]);
    my_putstr("my_pid:  ");
    my_put_nbr(p->pid);
    if (kill(p->pid_2, SIGUSR1) == -1)
        return (FAIL);
    my_putstr("\nsuccessfully connected\n\n");
    m->map = fill_empty_map(m->map);
    m->map = fill_map_w_boats(m->map, pos);
    m->map_e = fill_empty_map(m->map_e);
    display_all(m->map, m->map_e);
    while (game2(m) != TRUE);
    if (p->check_eof == 1)
        return (SUCCESS);
    return (end_player_two(m));
}
