/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-navy-quentin.brejoin
** File description:
** navy
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

/******************************STRUCTURS***************************************/

typedef struct obj_pos
{
    int **pos;
    int nb;
}obj_pos_t;

typedef struct game
{
    char **map;
    int block;
    int lenght;
    int width;
    int **obj;
    int nb_x;
} game_t;


/******************************globals_var*************************************/


/******************************includes****************************************/

    #include "../lib/my/include/my.h"
    #include <curses.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>

/******************************fonctions***************************************/

void sokoban(int ac, char **av);
void game_main(char *filepath);
char **go_up(char **map, int *pos, int **obj, game_t *game);
char **go_down(char **map, int *pos, int **obj, game_t *game);
char **go_left(char **map, int *pos, int **obj, game_t *game);
char **go_right(char **map, int *pos, int **obj, game_t *game);
void game_end(game_t *game);
int *find_player_pos(char **map);
int **find_objective_pos(char **map, char *filepath, char c);
int find_all_zero(char *filepath, char c);
int was_a_zero(int *pos, int **obj, int nb1, int nb2);
int check_block(game_t *game);
void error_file(char *filepath);
void print_map(game_t *game);
int find_x(char *filepath);

#endif /* !MINISHELL_H_ */
