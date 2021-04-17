/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int n = 0;

    while (dest[n] != '\0')
        n++;
    while (i < nb) {
        if (src[i] != 0)
            dest[n] = src[i];
        else
            dest[n] = '\0';
        n++;
        i++;
    }
    return (dest);
}