/*
** EPITECH PROJECT, 2020
** navy
** File description:
** checks if one of the players has won
*/

#include "navy.h"

player_t *p;

void handl_sig_defeat(int sig, siginfo_t *inf, void *context)
{
    (void)context;
    (void)inf;
    if (sig == SIGUSR1)
        p->defeat = 1;
    if (sig == SIGUSR2)
        p->defeat = 0;
}

void receive_win(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_mask = mask;
    sa.sa_sigaction = handl_sig_defeat;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_putstr("Error: cannot handle SIGUSR1\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_putstr("Error: cannot handle SIGUSR2\n");
    while (p->defeat == 2)
        usleep(100);
}

int defeat_check(void)
{
    if (p->turn == 1) {
        usleep(1000);
        kill(p->pid_2, SIGUSR2);
        usleep(1000);
        receive_win();
        if (p->defeat == 1)
            return (TRUE);
    } else {
        receive_win();
        if (p->defeat == 1)
            return (TRUE);
        usleep(2000);
        kill(p->pid_2, SIGUSR2);
    }
    return (FALSE);
}

int win_check(char **map)
{
    int hit = 0;

    p->defeat = 2;
    for (int i = 0; i != 10; i++)
        for (int j = 0; j != 17; j++)
            if (map[i][j] == 'x')
                hit++;
    if (hit != 14)
        return (defeat_check());
    else {
        usleep(2000);
        kill(p->pid_2, SIGUSR1);
        return (TRUE);
    }
}

int count_hit(char **map)
{
    int hit = 0;

    for (int i = 0; i != 10; i++)
        for (int j = 0; j != 17; j++)
            if (map[i][j] == 'x')
                hit++;
    return (hit);
}
