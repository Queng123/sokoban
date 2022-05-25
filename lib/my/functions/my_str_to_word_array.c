/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-bsminishell1-quentin.brejoin
** File description:
** env_content
*/

#include <stdlib.h>
#include "../include/my.h"

int is_printable(char c)
{
    if (c >= 33 && c <= 126)
        return (1);
    return (0);
}

char **malloc_without_know_size(char *str)
{
    char **word_array;
    int j = 1;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ' || str[i] == '\n' && str[i + 1] != ' ')
            j++;
    word_array = malloc(sizeof(char *) * (j + 1));
    j = 0;
    for (int i = 0; str[i] != '\0'; i++, k++)
        if (str[i] == ' ' && str[i + 1] != ' ') {
            word_array[j] = malloc(sizeof(char) * k);
            k = 0;
            i++;
            j++;
        }
    word_array[j] = malloc(sizeof(char) * k);
    return (word_array);
}

char *manage_gillemets(char *str, char *array, int i)
{
    for (int k = 0; str[i] != '\"'; i++, k++) {
        array[k] = str[i];
    }
    return (array);
}

char **my_str_to_word_array(char *str)
{
    char **word_array = malloc_without_know_size(str);
    int j = 0;

    for (int i = 0, k = 0; str[i] != '\0'; i++) {
        if (is_printable(str[i]) == 0 && is_printable(str[i + 1]) != 0) {
            k = 0;
            j++;
            continue;
        }
        if (is_printable(str[i]) == 0) continue;
        if (str[i] == '\"') {
            i++;
            word_array[j] = manage_gillemets(str, word_array[j], i);
            i += my_strlen(word_array[j]) + 1;
            continue;
        }
        word_array[j][k] = str[i];
        k++;
    }
    word_array[j + 1] = NULL;
    return (word_array);
}
