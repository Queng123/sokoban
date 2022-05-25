/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my library
*/

#include <stdarg.h>

#ifndef TEST_H_

    #define TEST_H_

void my_putchar(char c);

char *my_strstr(char *str, char const *to_find);

int my_isneg(int nb);

int my_strcmp(char const *s1, char const *s2);

int my_put_nbr(long nb);

int my_strncmp(char const *s1, char const *s2, int n);

void my_swap(int *a, int *b);

char *my_strupcase(char *str);

int my_putstr(char const *str);

char *my_strlowcase(char *str);

int my_strlen(char const *str);

char *my_strcapitalize(char *str);

int my_getnbr(char const *str);

int my_str_isalpha(char const *str);

void my_sort_int_array(int *tab, int size);

int my_str_isnum(char const *str);

int my_compute_power_rec(int nb, int power);

int my_str_islower(char const *str);

int my_compute_square_root(int nb);

int my_str_isupper(char const *str);

int my_is_prime(int nb);

int my_str_isprintable(char const *str);

int my_find_prime_sup(int nb);

int my_showstr(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_showmem(char const *str, int size);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strcat(char *dest, char const *src);

char *my_revstr(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_checker(char *str, int i);

char *my_itoa(int nb);

long my_strtol(char **str);

void my_putcharf(va_list ap);

void my_put_nbrf(va_list ap);

void my_putstrf(va_list ap);

void my_printf(char *str, ...);

void my_printoctal(va_list ap);

void my_printhexa(va_list ap);

void my_printbighexa(va_list ap);

void my_binary_conversion(va_list ap);

int my_putchar_mod(va_list ap, int j);

void my_print_adress(va_list ap);

void my_printf(char *str, ...);

void my_put_bigstr(va_list ap);

char my_nbr_to_char(char c);

void my_put_nbr_unsigned(va_list ap);

int my_check_hashtag(int i, va_list ap, char c);

void *my_memset(void *, int, int);

void *my_calloc(int elem_count, int elem_size);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

char **load_2d_arr_from_file(char *filepath , int nb_rows , int nb_cols);

void print_array_str(char **str);

int fs_open_file(char *filepath);

int my_buff(char *filepath);

void free_double_array(char **str);

char **my_str_to_word_array(char *str);

int my_array_len(char **array);

char *my_strdup(char const *str);

char **my_arraycat(char **dest , char **src);

char **my_arraydup(char **src);

char **my_arraycpy(char **dest , char **src);

int get_width(char *filepath);

int get_rows(char *filepath);

#endif /* TEST_H_ */
