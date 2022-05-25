/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** find_objective_pos
*/

#include "sokoban.h"

int find_all_zero(char *filepath, char c)
{
    int index = fs_open_file(filepath);
    int buffer_size = my_buff(filepath);
    char *buf = malloc(sizeof(*buf) * (my_buff(filepath) + 1));
    int nb = 0;

    read(index, buf, buffer_size);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == c)
            nb++;
    free(buf);
    close(index);
    return (nb);
}

obj_pos_t find_pos(char **map, int i, obj_pos_t obj_pos_s, char c)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == c) {
            obj_pos_s.pos[obj_pos_s.nb][0] = i;
            obj_pos_s.pos[obj_pos_s.nb][1] = j;
            obj_pos_s.nb++;
            obj_pos_s.pos[obj_pos_s.nb] = malloc(sizeof(int) * 3);
        }
    }
    return (obj_pos_s);
}

int **find_objective_pos(char **map, char *filepath, char c)
{
    obj_pos_t obj_pos_s;
    int **nb = NULL;

    obj_pos_s.pos = malloc(sizeof(int) * find_all_zero(filepath, c) + 1);
    obj_pos_s.nb = 0;
    obj_pos_s.pos[0] = malloc(sizeof(int) * 3);
    for (int i = 0; map[i] != NULL; i++) {
        obj_pos_s = find_pos(map, i, obj_pos_s, c);
    }
    obj_pos_s.pos[obj_pos_s.nb] = NULL;
    nb = obj_pos_s.pos;
    return (nb);
}
