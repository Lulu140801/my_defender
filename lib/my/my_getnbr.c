/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        result = result * 10;
        result = result + (str[i] - 48);
    }
    return (result);
}