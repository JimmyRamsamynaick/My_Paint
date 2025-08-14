/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_putstr.c
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    
    if (!str)
        return 0;
    
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    
    return i;
}
