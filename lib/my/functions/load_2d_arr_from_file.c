/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-bsbsq-quentin.brejoin
** File description:
** load_2d_arr_from_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

int my_buff(char *filepath)
{
    struct stat st;
    int x = 0;

    stat(filepath, &st);
    x = st.st_size;
    return (x);
}

char **load_array(char **str, int nb_rows , int nb_cols, char *buf)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int i = 0;

    for (i = 0; i != nb_cols + 1; i++)
        str[x][i] = ' ';
    x++;
    for (; x != nb_rows + 1; x++) {
        for (y = 0; buf[z] != '\n'; y++, z++)
            str[x][y] = buf[z];
        z++;
        for (i = y; i != nb_cols + 1; i++)
            str[x][i] = ' ';
        str[x][i + 1] = '\0';
    }
    for (x += 1, i = 0; i != nb_cols + 1; i++)
        str[x][i] = ' ';
    str[x + 1] = NULL;
    return (str);
}

char **load_2d_arr_from_file(char *filepath, int nb_rows, int nb_cols)
{
    int index = fs_open_file(filepath);
    int buffer_size = my_buff(filepath);
    char *buf = my_calloc(sizeof(char), (my_buff(filepath) + 1));
    char **str = mem_alloc_2d_array(nb_rows + 3, nb_cols + 1);

    read(index, buf, buffer_size);
    str = load_array(str, nb_rows, nb_cols, buf);
    free(buf);
    close(index);
    return (str);
}
