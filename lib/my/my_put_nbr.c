/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_put_nbr.c
*/

int my_putchar(char c);

int my_put_nbr(int nb)
{
    int count = 0;
    
    if (nb < 0) {
        my_putchar('-');
        count++;
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
            count++;
        } else {
            nb = -nb;
        }
    }
    
    if (nb >= 10) {
        count += my_put_nbr(nb / 10);
    }
    
    my_putchar(nb % 10 + '0');
    count++;
    
    return count;
}
