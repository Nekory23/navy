/*
** EPITECH PROJECT, 2020
** navy
** File description:
** print_attack
*/

#include "navy.h"

player_t *p;

char trans_x(int x)
{
    char c;

    switch (x) {
    case 2 : c = 'A';
        break;
    case 4 : c = 'B';
        break;
    case 6 : c = 'C';
        break;
    case 8 : c = 'D';
        break;
    case 10 : c = 'E';
        break;
    case 12 : c = 'F';
        break;
    case 14 : c = 'G';
        break;
    case 16 : c = 'H';
        break;
    }
    return (c);
}

void print_attack(void)
{
    char lettre = trans_x(p->x);

    my_putchar(lettre);
    my_put_nbr(p->y - 1);
    if (p->attack == 2)
        my_putstr(": missed\n\n");
    if (p->attack == 1)
        my_putstr(": hit\n\n");
}
