/*
** EPITECH PROJECT, 2021
** display_game.c
** File description:
** display_game
*/

#include "my.h"
#include "objet.h"

void print_tower(animation_t *ani)
{
    sfCircleShape *test;
    sfVector2f pos;
    sfColor color = sfColor_fromRGBA(147, 138, 138, 127.5);

    for (int i = 0; i < ani->tower->place_taken; i++) {
        test = sfCircleShape_create();
        pos = sfSprite_getPosition(ani->tower->place_tower[i]);
        sfCircleShape_setPosition(test, pos);
        sfCircleShape_setFillColor(test, color);
        sfCircleShape_setRadius(test, 250);
        sfCircleShape_setOrigin(test, (sfVector2f) {260, 260});
        sfRenderWindow_drawCircleShape(ani->window, test, NULL);
    }
    for (int i = 0; i < ani->tower->place_taken; i++)
        sfRenderWindow_drawSprite(ani->window,
            ani->tower->place_tower[i], NULL);
    return;
}

void display_game(animation_t *ani)
{
    sfRenderWindow_drawSprite(ani->window, ani->back, NULL);
    sfRenderWindow_drawSprite(ani->window, ani->s_life, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(ani->window, ani->tower->price[i], NULL);
    print_tower(ani);
    animation_enemies(ani);
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