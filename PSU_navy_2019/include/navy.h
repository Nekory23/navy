/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <signal.h>

typedef struct map
{
    char **map;
    char **map_e;
} map_t;

typedef struct player
{
    int pid;
    int pid_2;
    int check;
    int attack;
    int x;
    int y;
    int count;
    char *str;
    int defeat;
    int turn;
    int check_eof;
} player_t;

int start(int ac, char **av);
char **split_pos(char *buffer);
int player_one(map_t *m);
int player_two(char **av, map_t *m);
int game1(map_t *m);
int game2(map_t *m);
int win_check(char **map);
int count_hit(char **map);
char *gnl(void);
int quit_game(void);

int display_h(void);
int error_handling(int ac, char **av);
char *clean_buffer(char *buffer);
int count_boats(char *buffer);
int check_pos(char **pos);
char **open_file(char *path);

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);
int my_put_nbr(int nb);
int my_atoi(char const *str);
void write_error(char *str);

char **fill_empty_map(char **map);
char **fill_map_w_boats(char **map, char **pos);
int catoi(char c);
int catoi1(char c);
void display_all(char **map, char **map_e);

void map_update_e(map_t *m, int x, int y);
void map_update(map_t *m);
int check_co_map(char **map);

void multi_kill(int nb1, int nb2);
void send_answer(int attack);
void print_attack(void);
void connect(void);
int multi_receive(void);
void receive_answer(void);

#define SUCCESS 0
#define ERROR 84
#define FALSE 0
#define TRUE 1
#define FAIL -1

#define READ_SIZE 32

#define USE "./navy [first_player_pid] navy_positions\n"
#define FPP "only for the 2nd player.  pid of the first player.\n"
#define NP "file representing the positions of the ships.\n"

#define STR_ERROR_ARG "this program must take 2 or 3 arguments\n"
#define STR_ERROR_OPEN "could not open or read file\n"
#define STR_ERROR_NBR "there must be 4 boats in the file\n"
#define STR_ERROR_SIZE_B "the size of the boats are invalid\n"
#define STR_ERROR_OUT "one or more boat is outside the map\n"
#define STR_ERROR_OVERLAP "boats are overlapping\n"

#endif
