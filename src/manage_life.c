/*
** EPITECH PROJECT, 2021
** manage_life.c
** File description:
** manage life
*/

#include "my.h"
#include "objet.h"

int init_life(animation_t *ani)
{
    sfTexture *texture = sfTexture_createFromFile("life.png", \
                        &(sfIntRect) {0, 0, 48, 14});

    if (!texture)
        return (84);
    ani->s_life = sfSprite_create();
    sfSprite_setTexture(ani->s_life, texture, sfFalse);
    sfSprite_setScale(ani->s_life, (sfVector2f) {4, 4});
    sfSprite_setOrigin(ani->s_life, (sfVector2f) {24, 7});
    sfSprite_setPosition(ani->s_life, (sfVector2f) {1800, 50});
    ani->life = 6;
    return (0);
}

void remove_life(animation_t *ani)
{
    sfIntRect rect = sfSprite_getTextureRect(ani->s_life);

    rect.width -= 8;
    ani->life--;
    sfSprite_setTextureRect(ani->s_life, rect);
}