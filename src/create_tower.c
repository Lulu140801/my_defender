/*
** EPITECH PROJECT, 2021
** create_tower.c
** File description:
** create_tower
*/

#include "../include/my.h"
#include "../include/objet.h"

void create_low_tower(tower_t *tower)
{
    sfTexture *texture;
    sfIntRect rect = (sfIntRect) {0, 0, 260, 316};
    int damage = 10;

    for (int i = 0; i < 3; i++, damage += 15) {
        tower->low_tower[i] = sfSprite_create();
        tower->low_damage[i] = damage;
        texture = sfTexture_createFromFile("Towers/tower01.png", &rect);
        sfSprite_setTexture(tower->low_tower[i], texture, sfFalse);
        sfSprite_setScale(tower->low_tower[i], (sfVector2f) {0.6, 0.6});
        sfSprite_setOrigin(tower->low_tower[i], \
                        (sfVector2f) {260 / 2, 316 / 2});
        free(texture);
        rect.left += 260;
    }
    sfSprite_setPosition(tower->low_tower[0], (sfVector2f) {300, 620});
}

void create_mid_tower(tower_t *tower)
{
    sfTexture *texture;
    sfIntRect rect = (sfIntRect) {0, 0, 260, 316};
    int damage = 30;

    for (int i = 0; i < 3; i++, damage += 15) {
        tower->mid_tower[i] = sfSprite_create();
        tower->mid_damage[i] = damage;
        texture = sfTexture_createFromFile("Towers/Tower02.png", &rect);
        sfSprite_setTexture(tower->mid_tower[i], texture, sfFalse);
        sfSprite_setScale(tower->mid_tower[i], (sfVector2f) {0.6, 0.6});
        sfSprite_setOrigin(tower->mid_tower[i], \
                        (sfVector2f) {260 / 2, 316 / 2});
        free(texture);
        rect.left += 260;
    }
    sfSprite_setPosition(tower->mid_tower[0], (sfVector2f) {570, 620});
}

void create_up_tower(tower_t *tower)
{
    sfTexture *texture;
    sfIntRect rect = (sfIntRect) {0, 0, 260, 316};
    int damage = 65;

    for (int i = 0; i < 3; i++, damage += 15) {
        tower->up_tower[i] = sfSprite_create();
        tower->up_damage[i] = damage;
        texture = sfTexture_createFromFile("Towers/Tower03.png", &rect);
        sfSprite_setTexture(tower->up_tower[i], texture, sfFalse);
        sfSprite_setScale(tower->up_tower[i], (sfVector2f) {0.6, 0.6});
        sfSprite_setOrigin(tower->up_tower[i], \
                        (sfVector2f) {260 / 2, 316 / 2});
        free(texture);
        rect.left += 260;
    }
    sfSprite_setPosition(tower->up_tower[0], (sfVector2f) {300, 860});
}

void create_ultra_tower(tower_t *tower)
{
    sfTexture *texture;
    sfIntRect rect = (sfIntRect) {0, 0, 260, 316};
    int damage = 100;

    for (int i = 0; i < 3; i++, damage += 15) {
        tower->ultra_tower[i] = sfSprite_create();
        tower->ultra_damage[i] = damage;
        texture = sfTexture_createFromFile("Towers/Tower04.png", &rect);
        sfSprite_setTexture(tower->ultra_tower[i], texture, sfFalse);
        sfSprite_setScale(tower->ultra_tower[i], (sfVector2f) {0.6, 0.6});
        sfSprite_setOrigin(tower->ultra_tower[i], \
                            (sfVector2f) {260 / 2, 158});
        free(texture);
        rect.left += 260;
    }
    sfSprite_setPosition(tower->ultra_tower[0], (sfVector2f) {570, 860});
}

void create_all_tower(animation_t *ani)
{
    create_low_tower(ani->tower);
    create_mid_tower(ani->tower);
    create_up_tower(ani->tower);
    create_ultra_tower(ani->tower);
}