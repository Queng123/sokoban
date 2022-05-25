/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-BSQ-quentin.brejoin
** File description:
** get_width
*/

#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include <stdlib.h>

int get_rows(char *filepath)
{
    int j = open(filepath, O_RDONLY);
    int i = 0;
    int k = 0;
    char *buf = my_calloc(sizeof(buf), my_buff(filepath) + 1);
    int x = my_buff(filepath);

    read(j, buf, x);
    for (; buf[i] != '\0'; i++) {
        if (buf[i] == '\n')
            k++;
    }
    close(j);
    free(buf);
    return (k);
}

int get_width(char *filepath)
{
    int j = open(filepath, O_RDONLY);
    int i = 0;
    char *buf = my_calloc(sizeof(char), my_buff(filepath) + 1);
    int x = my_buff(filepath);
    int biggest = 0;
    int k = 0;

    read(j, buf, x);
    while (buf[i] != '\0') {
        for (k = 0; buf[i] != '\n'; i++, k++);
        if (biggest < k)
            biggest = k;
        i++;
    }
    close(j);
    free(buf);
    return (biggest);
}
