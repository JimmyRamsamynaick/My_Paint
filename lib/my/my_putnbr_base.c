/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-mypaint-jimmy.ramsamynaick
** File description:
** my_putnbr_base.c
*/

int my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int base_len;
    int count = 0;
    
    if (!base)
        return 0;
    
    base_len = my_strlen(base);
    if (base_len < 2)
        return 0;
    
    if (nbr < 0) {
        my_putchar('-');
        count++;
        if (nbr == -2147483648) {
            my_putchar(base[2]);
            nbr = -147483648;
            count++;
        } else {
            nbr = -nbr;
        }
    }
    
    if (nbr >= base_len) {
        count += my_putnbr_base(nbr / base_len, base);
    }
    
    my_putchar(base[nbr % base_len]);
    count++;
    
    return count;
}