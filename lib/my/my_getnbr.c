/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int sign = 1;
    
    if (!str)
        return 0;
    
    // Handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
        } else {
            break;
        }
        i++;
    }
    
    return nbr * sign;
}
