/*
** EPITECH PROJECT, 2021
** reset_pos_tower.c
** File description:
** reset_pos_tower
*/

#include "../include/my.h"
#include "../include/objet.h"

void reset_low_tower(animation_t *ani)
{
    sfSprite_setPosition(ani->tower->low_tower[0], \
            (sfVector2f) {300, 620});
}

void reset_mid_tower(animation_t *ani)
{
    sfSprite_setPosition(ani->tower->mid_tower[0], \
            (sfVector2f) {570, 620});
}

void reset_up_tower(animation_t *ani)
{
    sfSprite_setPosition(ani->tower->up_tower[0], \
            (sfVector2f) {300, 860});
}

void reset_ultra_tower(animation_t *ani)
{
    sfSprite_setPosition(ani->tower->ultra_tower[0], \
            (sfVector2f) {570, 860});
}

void reset_sort_tower(animation_t *ani)
{
    switch (ani->tower->grab) {
    case 0:
        reset_low_tower(ani);
        break;
    case 1:
        reset_mid_tower(ani);
        break;
    case 2:
        reset_up_tower(ani);
        break;
    case 3:
        reset_ultra_tower(ani);
        break;
    default:
        break;
    }
    ani->tower->grab = -1;
}