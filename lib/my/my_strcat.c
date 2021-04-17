/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = 0;

    while (dest[n] != '\0') {
        n++;
    }
    while (src[i] != '\0') {
        dest[n] = src[i];
        n++;
        i++;
    }
    return (dest);
}