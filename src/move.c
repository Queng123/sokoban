/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** move
*/

#include "sokoban.h"

int was_a_zero(int *pos, int **obj, int nb1, int nb2)
{
    for (int i = 0; obj[i] != NULL; i++) {
        if (obj[i][0] == pos[0] + nb1 && obj[i][1] == pos[1] + nb2) {
            return (0);
        }
    }
    return (1);
}

char **go_up(char **map, int *pos, int **obj, game_t *game)
{
    (void)game;
    if (map[pos[0] - 1][pos[1]] == '#' || pos[0] - 1 == 0)
        return (map);
    if (map[pos[0] - 1][pos[1]] == 'X') {
        if (map[pos[0] - 2][pos[1]] == '#' || map[pos[0] - 2][pos[1]] == 'X' ||
        pos[0] - 2 == 0)
            return (map);
        map[pos[0] - 2][pos[1]] = 'X';
    }
    if (was_a_zero(pos, obj, 0, 0) == 1)
        map[pos[0]][pos[1]] = ' ';
    else
        map[pos[0]][pos[1]] = 'O';
    map[pos[0] - 1][pos[1]] = 'P';
    return (map);
}

char **go_down(char **map, int *pos, int **obj, game_t *game)
{
    if (map[pos[0] + 1][pos[1]] == '#' || pos[0] + 1 == game->lenght + 1)
        return (map);
    if (map[pos[0] + 1][pos[1]] == 'X') {
        if (map[pos[0] + 2][pos[1]] == '#' || map[pos[0] + 2][pos[1]] == 'X' ||
        pos[0] + 2 == game->lenght + 1)
            return (map);
        map[pos[0] + 2][pos[1]] = 'X';
    }
    if (was_a_zero(pos, obj, 0, 0) == 1)
        map[pos[0]][pos[1]] = ' ';
    else
        map[pos[0]][pos[1]] = 'O';
    map[pos[0] + 1][pos[1]] = 'P';
    return (map);
}

char **go_left(char **map, int *pos, int **obj, game_t *game)
{
    (void)game;
    if (map[pos[0]][pos[1] - 1] == '#' || pos[1] - 1 == -1)
        return (map);
    if (map[pos[0]][pos[1] - 1] == 'X') {
        if (map[pos[0]][pos[1] - 2] == '#' || map[pos[0]][pos[1] - 2] == 'X' ||
        pos[1] - 2 == -1)
            return (map);
        map[pos[0]][pos[1] - 2] = 'X';
    }
    if (was_a_zero(pos, obj, 0, 0) == 1)
        map[pos[0]][pos[1]] = ' ';
    else
        map[pos[0]][pos[1]] = 'O';
    map[pos[0]][pos[1] - 1] = 'P';
    return (map);
}

char **go_right(char **map, int *pos, int **obj, game_t *game)
{
    if (map[pos[0]][pos[1] + 1] == '#' || pos[1] + 1 == game->width)
        return (map);
    if (map[pos[0]][pos[1] + 1] == 'X') {
        if (map[pos[0]][pos[1] + 2] == '#' || map[pos[0]][pos[1] + 2] == 'X' ||
        pos[1] + 2 == game->width)
            return (map);
        map[pos[0]][pos[1] + 2] = 'X';
    }
    if (was_a_zero(pos, obj, 0, 0) == 1)
        map[pos[0]][pos[1]] = ' ';
    else
        map[pos[0]][pos[1]] = 'O';
    map[pos[0]][pos[1] + 1] = 'P';
    return (map);
}
