/*
** EPITECH PROJECT, 2021
** update_ui.c
** File description:
** update_ui
*/

#include "../include/my.h"
#include "../include/objet.h"

void update_color_text(animation_t *ani)
{
    if (ani->money >= LOW_TOWER)
        sfText_setColor(ani->tower->price[0], sfGreen);
    else
        sfText_setColor(ani->tower->price[0], sfRed);
    if (ani->money >= MID_TOWER)
        sfText_setColor(ani->tower->price[1], sfGreen);
    else
        sfText_setColor(ani->tower->price[1], sfRed);
    if (ani->money >= UP_TOWER)
        sfText_setColor(ani->tower->price[2], sfGreen);
    else
        sfText_setColor(ani->tower->price[2], sfRed);
    if (ani->money >= ULTRA_TOWER)
        sfText_setColor(ani->tower->price[3], sfGreen);
    else
        sfText_setColor(ani->tower->price[3], sfRed);
}

void select_tower(animation_t * ani, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= 229 && pos_mouse.x <= 352 && \
        pos_mouse.y >= 553 && pos_mouse.y <= 700)
        sfSprite_setScale(ani->tower->low_tower[0], (sfVector2f) {0.7, 0.7});
    else
        sfSprite_setScale(ani->tower->low_tower[0], (sfVector2f) {0.6, 0.6});
    if (pos_mouse.x >= 488 && pos_mouse.x <= 651 && \
        pos_mouse.y >= 534 && pos_mouse.y <= 698)
        sfSprite_setScale(ani->tower->mid_tower[0], (sfVector2f) {0.7, 0.7});
    else
        sfSprite_setScale(ani->tower->mid_tower[0], (sfVector2f) {0.6, 0.6});
    if (pos_mouse.x >= 224 && pos_mouse.x <= 340 && \
        pos_mouse.y >= 766 && pos_mouse.y <= 940)
        sfSprite_setScale(ani->tower->up_tower[0], (sfVector2f) {0.7, 0.7});
    else
        sfSprite_setScale(ani->tower->up_tower[0], (sfVector2f) {0.6, 0.6});
    if (pos_mouse.x >= 502 && pos_mouse.x <= 624 && \
        pos_mouse.y >= 770 && pos_mouse.y <= 938)
        sfSprite_setScale(ani->tower->ultra_tower[0], (sfVector2f) {0.7, 0.7});
    else
        sfSprite_setScale(ani->tower->ultra_tower[0], (sfVector2f) {0.6, 0.6});
}

void grab_tower(animation_t *ani, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= 229 && pos_mouse.x <= 352 && \
        pos_mouse.y >= 553 && pos_mouse.y <= 700 && ani->money >= LOW_TOWER) {
        ani->tower->grab = 0;
    }
    if (pos_mouse.x >= 488 && pos_mouse.x <= 651 && \
        pos_mouse.y >= 534 && pos_mouse.y <= 698 && ani->money >= MID_TOWER) {
        ani->tower->grab = 1;
    }
    if (pos_mouse.x >= 224 && pos_mouse.x <= 340 && \
        pos_mouse.y >= 766 && pos_mouse.y <= 940 && ani->money >= UP_TOWER) {
        ani->tower->grab = 2;

    }
    if (pos_mouse.x >= 502 && pos_mouse.x <= 624 && \
        pos_mouse.y >= 770 && pos_mouse.y <= 938 && ani->money >= ULTRA_TOWER) {
        ani->tower->grab = 3;
    }
}