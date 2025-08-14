/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_itoa.c
*/

#include <stdlib.h>

static int get_nbr_len(int n)
{
    int len = 0;
    
    if (n == 0)
        return 1;
    
    if (n < 0) {
        len++;
        n = -n;
    }
    
    while (n > 0) {
        n /= 10;
        len++;
    }
    
    return len;
}

char *my_itoa(int value)
{
    char *str;
    int len;
    int i;
    int is_negative = 0;
    
    len = get_nbr_len(value);
    str = malloc(sizeof(char) * (len + 1));
    
    if (!str)
        return NULL;
    
    if (value < 0) {
        is_negative = 1;
        value = -value;
    }
    
    str[len] = '\0';
    i = len - 1;
    
    if (value == 0) {
        str[0] = '0';
        return str;
    }
    
    while (value > 0) {
        str[i] = (value % 10) + '0';
        value /= 10;
        i--;
    }
    
    if (is_negative)
        str[0] = '-';
    
    return str;
}