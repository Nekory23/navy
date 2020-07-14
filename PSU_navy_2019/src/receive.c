/*
** EPITECH PROJECT, 2020
** navy
** File description:
** recieve
*/

#include "navy.h"

player_t *p;

void handl_sig_answer(int sig, siginfo_t *inf, void *context)
{
    (void)context;
    (void)inf;
    if (sig == SIGUSR1)
        p->attack += 1;
    if (sig == SIGUSR2)
        p->attack += 2;
}

void receive_answer(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_mask = mask;
    sa.sa_sigaction = handl_sig_answer;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_putstr("Error: cannot handle SIGUSR1\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_putstr("Error: cannot handle SIGUSR2\n");
    while (p->attack == 0)
        usleep(100);
}

void handl_sig_mul_rec(int sig, siginfo_t *inf, void *context)
{
    (void)context;
    (void)inf;
    if (sig == SIGUSR1 && p->count == 0)
        p->check_eof += 1;
    if (sig == SIGUSR2)
        p->count += 1;
    if (sig == SIGUSR1) {
        if (p->count == 1)
            p->x += 1;
        if (p->count == 2)
            p->y += 1;
    }
}

int multi_receive(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_mask = mask;
    sa.sa_sigaction = handl_sig_mul_rec;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_putstr("Error: cannot handle SIGUSR1\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_putstr("Error: cannot handle SIGUSR2\n");
    while (p->count != 3) {
        if (p->check_eof == 1)
            return (ERROR);
        usleep(100);
    }
}
