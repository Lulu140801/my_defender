/*
** EPITECH PROJECT, 2021
** my_int_to_str
** File description:
** put an int on an string
*/

#include "../../include/my.h"

int verif_number(int number, int *verif)
{
    if (number < 0) {
        *verif = 1;
        number = number * -1;
    }
    return (number);
}

char *my_int_to_str(int number)
{
    int index = 0;
    int verif = 0;
    char *string_converted = malloc(sizeof(char) * 11 + 1);

    number = verif_number(number, &verif);
    if (number == 0) {
        string_converted[0] = '0';
        string_converted[1] = '\0';
        return (string_converted);
    }
    while (number > 0){
        string_converted[index] = number % 10 + 48;
        number = number / 10;
        index = index + 1;
    }
    if (verif == 1){
        string_converted[index] = '-';
        string_converted[index + 1] = '\0';
    } else string_converted[index] = '\0';
    string_converted = my_revstr(string_converted);
    return (string_converted);
}