/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my put char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
