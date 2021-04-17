/*
** EPITECH PROJECT, 2021
** animation
** File description:
** where is the animation
*/

#include "../include/my.h"
#include "../include/objet.h"

void animation_enemies(animation_t *ani)
{
    sfTexture *texture;

    if (ani->seconds > 0.1) {
        ani->r_enemies.left += 304;
        if (ani->r_enemies.left > 5777)
            ani->r_enemies.left = 0;
        texture = sfTexture_createFromFile("Ennemies/GreyEnnemie.png", \
                                            &ani->r_enemies);
        sfSprite_setTexture(ani->enemies, texture, sfFalse);
        free(texture);
        sfClock_restart(ani->clock);
    }
    mouv_sprite(ani);
    sfRenderWindow_drawSprite(ani->window, ani->enemies, NULL);
}

void mouv_sprite(animation_t *ani)
{
    int x1 = 10;
    int y1 = 10;
    int x2 = -10;
    int y2 = -10;

    sfVector2f pos = sfSprite_getPosition(ani->enemies);
    if (pos.x <= 450)
        sfSprite_move(ani->enemies, (sfVector2f) {x1, 0});
    if (pos.x >= 450 && pos.y <= 220 && pos.x <= 470)
        sfSprite_move(ani->enemies, (sfVector2f) {0, y1});
    if (pos.x >= 450 && pos.y >= 220 && pos.x <= 770)
        sfSprite_move(ani->enemies, (sfVector2f) {x1, 0});
    if (pos.x >= 770 && pos.y <= 230 && pos.y >= 50 && pos.x <= 780)
        sfSprite_move(ani->enemies, (sfVector2f) {0, y2});
    if (pos.x >= 770 && pos.y <= 60 && pos.x <= 1100)
        sfSprite_move(ani->enemies, (sfVector2f) {x1, 0});
    if (pos.x >= 1110 && pos.y >= 50 && pos.y <= 430)
        sfSprite_move(ani->enemies, (sfVector2f) {0, y1});
    if (pos.x <= 1110 && pos.x >= 760 && pos.y >= 420)
        sfSprite_move(ani->enemies, (sfVector2f) {x2, 0});
    if (pos.x <= 770 && pos.y <= 810 && pos.y >= 420)
        sfSprite_move(ani->enemies, (sfVector2f) {0, y1});
    if (pos.x >= 750 && pos.x <= 1110 && pos.y >= 800)
        sfSprite_move(ani->enemies, (sfVector2f) {x1, 0});
}