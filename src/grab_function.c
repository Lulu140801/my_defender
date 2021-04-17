/*
** EPITECH PROJECT, 2021
** grab_function.c
** File description:
** grab_function
*/

#include "../include/my.h"
#include "../include/objet.h"

void grab_low_tower(animation_t *ani, sfVector2i pos_mouse)
{
    sfSprite_setPosition(ani->tower->low_tower[0], \
            (sfVector2f) {pos_mouse.x, pos_mouse.y});
}

void grab_mid_tower(animation_t *ani, sfVector2i pos_mouse)
{
    sfSprite_setPosition(ani->tower->mid_tower[0], \
            (sfVector2f) {pos_mouse.x, pos_mouse.y});
}

void grab_up_tower(animation_t *ani, sfVector2i pos_mouse)
{
    sfSprite_setPosition(ani->tower->up_tower[0], \
            (sfVector2f) {pos_mouse.x, pos_mouse.y});
}

void grab_ultra_tower(animation_t *ani, sfVector2i pos_mouse)
{
    sfSprite_setPosition(ani->tower->ultra_tower[0], \
            (sfVector2f) {pos_mouse.x, pos_mouse.y});
}

void grab_sort_tower(animation_t *ani)
{
    switch (ani->tower->grab) {
    case 0:
        grab_low_tower(ani, sfMouse_getPositionRenderWindow(ani->window));
        break;
    case 1:
        grab_mid_tower(ani, sfMouse_getPositionRenderWindow(ani->window));
        break;
    case 2:
        grab_up_tower(ani, sfMouse_getPositionRenderWindow(ani->window));
        break;
    case 3:
        grab_ultra_tower(ani, sfMouse_getPositionRenderWindow(ani->window));
        break;
    default:
        break;
    }
}