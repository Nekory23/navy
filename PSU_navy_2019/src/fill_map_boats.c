/*
** EPITECH PROJECT, 2020
** navy
** File description:
** fill the map with boats
*/

#include "navy.h"

int catoi(char c)
{
    int nb = 0;

    switch (c) {
    case '1' : nb = 1;
        break;
    case '2' : nb = 2;
        break;
    case '3' : nb = 3;
        break;
    case '4' : nb = 4;
        break;
    case '5' : nb = 5;
        break;
    case '6' : nb = 6;
        break;
    case '7' : nb = 7;
        break;
    case '8' : nb = 8;
        break;
    }
    return (nb);
}

int catoi1(char c)
{
    int nb = 0;

    switch (c) {
    case 'A' : nb = 2;
        break;
    case 'B' : nb = 4;
        break;
    case 'C' : nb = 6;
        break;
    case 'D' : nb = 8;
        break;
    case 'E' : nb = 10;
        break;
    case 'F' : nb = 12;
        break;
    case 'G' : nb = 14;
        break;
    case 'H' : nb = 16;
        break;
    }
    return (nb);
}

char **fill_col(char **map, char **pos, int line, char nb)
{
    int nb1 = catoi(pos[line][3]) + 1;
    int nb2 = catoi(pos[line][6]) + 1;

    for (int i = 2; i != 17; i++)
        if (map[0][i] == pos[line][2])
            for (int j = nb1; j != nb2 + 1; j++)
                map[j][i] = nb;
    return (map);
}

char **fill_line(char **map, char **pos, int line, char nb)
{
    int li = catoi(pos[line][3]) + 1;
    int co = catoi1(pos[line][2]);
    int dif = pos[line][5] - pos[line][2] + 1;

    for (int i = 2; i != 17; i++)
        if (map[0][i] == pos[line][2])
            for (int j = 0; j != dif; co += 2, j++)
                map[li][co] = nb;
    return (map);
}

char **fill_map_w_boats(char **map, char **pos)
{
    for (int i = 2; i != 17; i++) {
        if (map[0][i] == pos[0][2])
            map[catoi(pos[0][3]) + 1][i] = '2';
        if (map[0][i] == pos[0][5])
            map[catoi(pos[0][6]) + 1][i] = '2';
    }
    for (int i = 1; i != 4; i++) {
        if (map == NULL)
            break;
        if (pos[i][2] == pos[i][5])
            map = fill_col(map, pos, i, pos[i][0]);
        else
            map = fill_line(map, pos, i, pos[i][0]);
    }
    return (map);
}
