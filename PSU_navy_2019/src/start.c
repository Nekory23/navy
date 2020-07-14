/*
** EPITECH PROJECT, 2020
** navy
** File description:
** test unitaires
*/

#include "navy.h"

player_t *p;
map_t *m;

void fill_struct(void)
{
    p->pid = 0;
    p->pid_2 = 0;
    p->check = 0;
    p->attack = 0;
    p->count = 0;
    p->x = 0;
    p->y = 0;
    p->check_eof = 0;
}

int start(int ac, char **av)
{
    int ret = 0;

    p = malloc(sizeof(player_t));
    m = malloc(sizeof(map_t));
    if (ac == 2 && my_strcmp(av[1], "-h"))
        return (display_h());
    if (error_handling(ac, av) == ERROR)
        return (ERROR);
    fill_struct();
    if (ac >= 2) {
        if (ac == 2)
            ret = player_one(m);
        if (ac == 3)
            if ((ret = player_two(av, m)) == FAIL)
                return (SUCCESS);
    }
    free(p);
    free(m);
    return (ret);
}
