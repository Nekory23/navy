/*
** EPITECH PROJECT, 2020
** navy
** File description:
** check if the postion of the boats is valid
*/

#include "navy.h"

map_t *m;

int is_in_map(char **pos)
{
    for (int i = 0; i != 4; i++) {
        if (pos[i][2] < 'A' || pos[i][2] > 'H'){
            write_error(STR_ERROR_OUT);
            return (ERROR);
        }
        if (pos[i][5] < 'A' || pos[i][5] > 'H'){
            write_error(STR_ERROR_OUT);
            return (ERROR);
        }
    }
    for (int i = 0; i != 4; i++) {
        if (pos[i][3] < '1' || pos[i][3] > '8'){
            write_error(STR_ERROR_OUT);
            return (ERROR);
        }
        if (pos[i][6] < '1' || pos[i][6] > '8'){
            write_error(STR_ERROR_OUT);
            return (ERROR);
        }
    }
    return (SUCCESS);
}

int is_right_size(char **pos)
{
    for (int i = 0, j = 1; i != 4; i++, j++) {
        if (pos[i][2] == pos[i][5])
            if ((pos[i][6] - pos[i][3]) != j) {
                write_error(STR_ERROR_SIZE_B);
                return (ERROR);
            }
        if (pos[i][2] != pos[i][5])
            if ((pos[i][5] - pos[i][2]) != j) {
                write_error(STR_ERROR_SIZE_B);
                return (ERROR);
            }
    }
    return (SUCCESS);
}

int comp_tab_nb(int *tab)
{
    if (tab[0] != 3 || tab[1] != 4) {
        free (tab);
        write_error(STR_ERROR_OVERLAP);
        return (ERROR);
    }
    if (tab[2] != 5 || tab[3] != 6) {
        free (tab);
        write_error(STR_ERROR_OVERLAP);
        return (ERROR);
    }
    return (SUCCESS);
}

int is_overlapping(char **pos)
{
    int *tab = malloc(sizeof(int) * 4);

    m->map = fill_empty_map(m->map);
    m->map = fill_map_w_boats(m->map, pos);
    for (int i = 0; m->map[i]; i++)
        for (int j = 0; m->map[i][j]; j++)
            switch (m->map[i][j]) {
            case '2' : tab[0] += 1;
                break;
            case '3' : tab[1] += 1;
                break;
            case '4' : tab[2] += 1;
                break;
            case '5' : tab[3] += 1;
                break;
            }
    if (comp_tab_nb(tab) == ERROR) {
        free (m);
        return (ERROR);
    }
    return (SUCCESS);
}

int check_pos(char **pos)
{
    for (int i = 2, j = 0; j != 4; j++, i++)
        if (my_atoi(pos[j]) != i) {
            write_error(STR_ERROR_SIZE_B);
            return (ERROR);
        }
    if (is_right_size(pos) == ERROR)
        return (ERROR);
    if (is_in_map(pos) == ERROR)
        return (ERROR);
    if (is_overlapping(pos) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
