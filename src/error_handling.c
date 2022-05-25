/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** error_handling
*/

#include "sokoban.h"

void check_buf(char *buf, int j)
{
    int p = 0;
    int x = 0;
    int o = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == 'P')
            p++;
        if (buf[i] == 'X')
            x++;
        if (buf[i] == 'O')
            o++;
    }
    free(buf);
    close(j);
    if (p != 1)
        exit(84);
    if (x != o)
        exit(84);
}

void error_file(char *filepath)
{
    int j = fs_open_file(filepath);
    int buffer_size = my_buff(filepath);
    char *buf = my_calloc(sizeof(*buf), (my_buff(filepath) + 1));

    if (j == -1)
        exit(84);
    read(j, buf, buffer_size);
    check_buf(buf, j);
}
