/*
** EPITECH PROJECT, 2020
** navy
** File description:
** send
*/

#include "navy.h"

player_t *p;

int quit_game(void)
{
    p->check_eof = 1;
    kill(p->pid_2, SIGUSR1);
    return (TRUE);
}

void send_answer(int attack)
{
    if (attack == 1)
        kill(p->pid_2, SIGUSR1);
    if (attack == 2)
        kill(p->pid_2, SIGUSR2);
}

void multi_kill(int nb1, int nb2)
{
    kill(p->pid_2, SIGUSR2);
    for (int i = 0; i != nb1; i++) {
        kill(p->pid_2, SIGUSR1);
        usleep(1000);
    }
    kill(p->pid_2, SIGUSR2);
    for (int i = 0; i != nb2; i++) {
        kill(p->pid_2, SIGUSR1);
        usleep(1000);
    }
    kill(p->pid_2, SIGUSR2);
}
