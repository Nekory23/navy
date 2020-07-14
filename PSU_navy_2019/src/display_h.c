/*
** EPITECH PROJECT, 2020
** navy
** File description:
** display_h
*/

#include "navy.h"

int display_h(void)
{
    my_putstr("USAGE\n     ");
    my_putstr(USE);
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid:  ");
    my_putstr(FPP);
    my_putstr("     navy_positions:  ");
    my_putstr(NP);
    return (SUCCESS);
}
