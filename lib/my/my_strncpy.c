/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n) {
        if (src[i] != 0)
            dest[i] = src[i];
        else
            dest[i] = '\0';
        i++;
    }
    dest[i] = '\0';
    return (dest);
}