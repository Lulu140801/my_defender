/*
** EPITECH PROJECT, 2021
** animation
** File description:
** where is the animation
*/

#include "my.h"
#include "objet.h"

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
    sfRenderWindow_drawSprite(ani->window, ani->enemies, NULL);
    animate_the_enemies(ani->enemies, ani);
}

void animate_the_enemies_3(sfSprite *enemy, sfVector2f pos_of_the_enemy, \
                            animation_t *ani)
{
    if (pos_of_the_enemy.x < 1510 && pos_of_the_enemy.y <= 710 &&
        pos_of_the_enemy.x >= 1190) {
        sfSprite_move(enemy, (sfVector2f) { 5, 0});
    }
    if (pos_of_the_enemy.x >= 1510 && pos_of_the_enemy.y < 880) {
        sfSprite_move(enemy, (sfVector2f) { 0, 5});
        pos_of_the_enemy = sfSprite_getPosition(enemy);
    }
    if (pos_of_the_enemy.x < 1920 && pos_of_the_enemy.y >= 880 &&
        pos_of_the_enemy.x >= 1510)
        sfSprite_move(enemy, (sfVector2f) { 5, 0});
    if (pos_of_the_enemy.x == 1920 && pos_of_the_enemy.y == 880) {
        sfSprite_setPosition(enemy, (sfVector2f) {-50, 120});
        remove_life(ani);
    }
}

void animate_the_enemies_2(sfSprite *enemy, sfVector2f pos_of_the_enemy, \
                            animation_t *ani)
{
    if (pos_of_the_enemy.x <= 850 && pos_of_the_enemy.y < 880 &&
        pos_of_the_enemy.y >= 510)
        sfSprite_move(enemy, (sfVector2f) { 0, 5});
    if (pos_of_the_enemy.x < 1190 && pos_of_the_enemy.y == 880 &&
        pos_of_the_enemy.x >= 790)
        sfSprite_move(enemy, (sfVector2f) { 5, 0});
    if (pos_of_the_enemy.x >= 1190 && pos_of_the_enemy.y >= 710 &&
        pos_of_the_enemy.x < 1435)
        sfSprite_move(enemy, (sfVector2f) { 0, -5});
    animate_the_enemies_3(enemy, pos_of_the_enemy, ani);
}

void animate_the_enemies_1(sfSprite *enemy, sfVector2f pos_of_the_enemy, \
                            animation_t *ani)
{
    if (pos_of_the_enemy.x >= 840 && pos_of_the_enemy.y > 120 &&
        pos_of_the_enemy.x < 1120 && pos_of_the_enemy.y <= 300)
        sfSprite_move(enemy, (sfVector2f) { 0, -5});
    if (pos_of_the_enemy.y <= 120 && pos_of_the_enemy.x < 1180 &&
        pos_of_the_enemy.x >= 780)
        sfSprite_move(enemy, (sfVector2f) { 5, 0});
    if (pos_of_the_enemy.x >= 1180 && pos_of_the_enemy.y < 510)
        sfSprite_move(enemy, (sfVector2f) { 0, 5});
    if (pos_of_the_enemy.x > 850 && pos_of_the_enemy.y >= 510 &&
        pos_of_the_enemy.y < 520)
        sfSprite_move(enemy, (sfVector2f) { -5, 0});
    animate_the_enemies_2(enemy, pos_of_the_enemy, ani);
}

void animate_the_enemies(sfSprite *enemy, animation_t *ani)
{
    sfVector2f pos_of_the_enemy = sfSprite_getPosition(enemy);

    if (pos_of_the_enemy.x < 510 && pos_of_the_enemy.y == 120)
        sfSprite_move(enemy, (sfVector2f) { 5, 0 });
    if (pos_of_the_enemy.x >= 510 && pos_of_the_enemy.x < 720 &&
        pos_of_the_enemy.y < 300 && pos_of_the_enemy.y >= 120)
        sfSprite_move(enemy, (sfVector2f) { 0, 5});
    if (pos_of_the_enemy.y >= 300 && pos_of_the_enemy.x < 840)
        sfSprite_move(enemy, (sfVector2f) { 5, 0 });
    animate_the_enemies_1(enemy, pos_of_the_enemy, ani);
}