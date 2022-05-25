/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** game_main
*/

#include "sokoban.h"

void print(game_t *game)
{
    int i = 0;
    int row = 0;
    int col = 0;

    clear();
    getmaxyx(stdscr, row, col);
    if (!(game->lenght > row || game->width > col))
        for (; game->map[i] != NULL; i++) {
            mvprintw(((row - game->lenght) / 2 + i), \
            ((col - game->width) / 2), "%s", game->map[i]);
        }
    else
        mvprintw((row / 2), (col / 2 - 10), "%s", "enlarge the terminal");
    refresh();
}

void print_map(game_t *game)
{
    print(game);
    for (int i = 0; game->obj[i] != NULL; i++) {
        if (game->map[game->obj[i][0]][game->obj[i][1]] != 'O') {
            game->map[game->obj[i][0]][game->obj[i][1]] = \
            (game->map[game->obj[i][0]][game->obj[i][1]] == 'P') ? 'P' : 'X';
        } else
            game->map[game->obj[i][0]][game->obj[i][1]] = 'O';
    }
}

void manage_input(int input, game_t *game)
{
    int key[] = {66, 65, 68, 67, -1};
    int *pos = find_player_pos(game->map);
    char **(*p[12])(char **map, int *pos, int **obj, game_t *game) = \
    {go_down, go_up, go_left, go_right};

    for (int i = 0; key[i] != -1; i++) {
        if (input == key[i]) {
            game->map = (*p[i])(game->map, pos, game->obj, game);
            free(pos);
            return;
        }
    }
    free(pos);
}

void game_loop(char *filepath, game_t *game)
{
    int input = 0;

    game->map = load_2d_arr_from_file(filepath, game->lenght, game->width);
    game->obj = find_objective_pos(game->map, filepath, 'O');
    game->nb_x = find_x(filepath);
    while (input != ' ') {
        print_map(game);
        input = getch();
        manage_input(input, game);
        game_end(game);
    }
    free_double_array(game->map);
    game_loop(filepath, game);
}

void game_main(char *filepath)
{
    game_t *game = malloc(sizeof(game_t));

    game->block = 0;
    game->width = get_width(filepath);
    game->lenght = get_rows(filepath);
    initscr();
    noecho();
    curs_set(0);
    game_loop(filepath, game);
}
