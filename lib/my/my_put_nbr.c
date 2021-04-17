/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < -2147483647 || nb > 2147483648)
        return (84);
    if (nb > 9)
        my_put_nbr(nb / 10);
    if (nb < 0 && nb > -10) {
        my_putchar('-');
    } else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb / -10);
    }
    if (nb >= 0)
        my_putchar(nb % 10 + '0');
    else if (nb < 0)
        my_putchar(- nb % 10 + '0');
    return (0);
}