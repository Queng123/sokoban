/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** find_player_pos
*/

#include "sokoban.h"

int *find_nb(char **map, int i, int *pos)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'P') {
            pos[0] = i;
            pos[1] = j;
            return (pos);
        }
    }
    return (pos);
}

int *find_player_pos(char **map)
{
    int *pos = malloc(sizeof(int) * 2);

    pos[0] = -1;
    for (int i = 0; map[i] != NULL; i++) {
        find_nb(map, i, pos);
        if (pos[0] != -1) {
            return (pos);
        }
    }
    return (pos);
}
