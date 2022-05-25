/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** game_end
*/

#include "sokoban.h"

int check_line(char *line)
{
    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] == 'O')
            return (0);
    }
    return (1);
}

int check_is_end(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        if (check_line(map[i]) == 0)
            return (0);
    }
    return (1);
}

void game_end(game_t *game)
{
    int *pos = find_player_pos(game->map);

    if (check_is_end(game->map) == 1 && was_a_zero(pos, game->obj, 0, 0) == 1) {
        print_map(game);
        clear();
        free_double_array(game->map);
        free(game);
        exit(0);
    }
    if (check_block(game) == game->nb_x) {
        print_map(game);
        clear();
        free_double_array(game->map);
        free(game);
        exit(1);
    } else {
        game->block = 0;
    }
}
