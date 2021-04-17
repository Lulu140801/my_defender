/*
** EPITECH PROJECT, 2021
** display_game.c
** File description:
** display_game
*/

#include "../include/my.h"
#include "../include/objet.h"

void display_game(animation_t *ani)
{
    sfRenderWindow_drawSprite(ani->window, ani->back, NULL);
    animation_enemies(ani);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(ani->window, ani->tower->price[i], NULL);
    sfRenderWindow_drawSprite(ani->window, ani->tower->low_tower[0], NULL);
    sfRenderWindow_drawSprite(ani->window, ani->tower->mid_tower[0], NULL);
    sfRenderWindow_drawSprite(ani->window, ani->tower->up_tower[0], NULL);
    sfRenderWindow_drawSprite(ani->window, ani->tower->ultra_tower[0], NULL);
    update_color_text(ani);
    if (ani->tower->grab != -1)
        grab_sort_tower(ani);
}

void display_menu(animation_t *ani)
{
    sfRenderWindow_drawSprite(ani->window, ani->menu->back, NULL);
}