/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++) {
    }
    return (nb);
}

int my_strlen_c(int nb, char *buffer)
{
    int x = 0;

    for (; buffer[nb] != '\n'; nb++, x++);
    return (x);
}