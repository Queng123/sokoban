/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-quentin.brejoin
** File description:
** sokoban
*/

#include "sokoban.h"

void print_infos(void)
{
    my_putstr("USAGE\n"\
        "./my_sokoban map\n"\
        "DESCRIPTION\n"\
        "map file representing the warehouse map, containing ‘#’ for walls,\n"\
        "‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.\n");
    exit(0);
}

void sokoban(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        print_infos();
    error_file(av[1]);
    game_main(av[1]);
}
