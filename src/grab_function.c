/*
** EPITECH PROJECT, 2021
** grab_function.c
** File description:
** grab_function
*/

#include "my.h"
#include "objet.h"

void grab_sort_tower(animation_t *ani)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(ani->window);

    if (ani->tower->grab == 0)
        sfSprite_setPosition(ani->tower->low_tower[0], \
                (sfVector2f) {pos_mouse.x, pos_mouse.y});
    if (ani->tower->grab == 1)
        sfSprite_setPosition(ani->tower->mid_tower[0], \
            (sfVector2f) {pos_mouse.x, pos_mouse.y});
    if (ani->tower->grab == 2)
        sfSprite_setPosition(ani->tower->up_tower[0], \
                (sfVector2f) {pos_mouse.x, pos_mouse.y});
    if (ani->tower->grab == 3)
        sfSprite_setPosition(ani->tower->ultra_tower[0], \
            (sfVector2f) {pos_mouse.x, pos_mouse.y});
}

void reset_sort_tower(animation_t *ani)
{
    if (ani->tower->grab == 0)
        sfSprite_setPosition(ani->tower->low_tower[0], \
            (sfVector2f) {300, 620});
    if (ani->tower->grab == 1)
        sfSprite_setPosition(ani->tower->mid_tower[0], \
            (sfVector2f) {570, 620});
    if (ani->tower->grab == 2)
        sfSprite_setPosition(ani->tower->up_tower[0], \
            (sfVector2f) {300, 860});
    if (ani->tower->grab == 3)
        sfSprite_setPosition(ani->tower->ultra_tower[0], \
            (sfVector2f) {570, 860});
    ani->tower->grab = -1;
}

void set_tower(int nb, animation_t *ani, int i)
{
    if (ani->tower->grab == 0) {
        ani->tower->damage_tower[nb] = ani->tower->low_damage[0];
        ani->tower->place_tower[nb] = sfSprite_copy(ani->tower->low_tower[0]);
    }
    if (ani->tower->grab == 1) {
        ani->tower->damage_tower[nb] = ani->tower->mid_damage[0];
        ani->tower->place_tower[nb] = sfSprite_copy(ani->tower->mid_tower[0]);
    }
    if (ani->tower->grab == 2) {
        ani->tower->damage_tower[nb] = ani->tower->up_damage[0];
        ani->tower->place_tower[nb] = sfSprite_copy(ani->tower->up_tower[0]);
    }
    if (ani->tower->grab == 3) {
        ani->tower->damage_tower[nb] = ani->tower->ultra_damage[0];
        ani->tower->place_tower[nb] = sfSprite_copy \
        (ani->tower->ultra_tower[0]);
    }
    sfSprite_setPosition(ani->tower->place_tower[nb], \
        (sfVector2f) {ani->tower->pos[i][0], ani->tower->pos[i][1]});
}

void set_tower_pos(animation_t *ani, sfVector2i pos_mouse)
{
    if (ani->tower->place_taken == 10)
        return;
    for (int i = 0; i < 10; i++) {
        if (pos_mouse.x > (ani->tower->pos[i][0] - 100) && \
            pos_mouse.x < (ani->tower->pos[i][0] + 100) && \
            pos_mouse.y > (ani->tower->pos[i][1] - 100) && \
            pos_mouse.y < (ani->tower->pos[i][1] + 100)) {
                set_tower(ani->tower->place_taken, ani, i);
                ani->tower->place_taken++;
                break;
        }
    }
}