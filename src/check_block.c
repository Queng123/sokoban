/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** check_block
*/

#include "sokoban.h"

int find_x(char *filepath)
{
    int index = fs_open_file(filepath);
    int buffer_size = my_buff(filepath);
    char *buf = malloc(sizeof(*buf) * (my_buff(filepath) + 1));
    int nb = 0;

    read(index, buf, buffer_size);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == 'X')
            nb++;
    free(buf);
    close(index);
    return (nb);
}

int check_x(char **map, int j, int i)
{
    if (map[i + 1][j] == '#' && map[i][j + 1] == '#')
        return (1);
    if (map[i - 1][j] == '#' && map[i][j - 1] == '#')
        return (1);
    if (map[i + 1][j] == '#' && map[i][j - 1] == '#')
        return (1);
    if (map[i - 1][j] == '#' && map[i][j + 1] == '#')
        return (1);
    return (0);
}

int check_border(char *line, char **map, int i, game_t *game)
{
    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] == 'X')
            game->block += check_x(map, j, i);
    }
    return (game->block);
}

int check_block(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        check_border(game->map[i], game->map, i, game);
    }
    return (game->block);
}
