/*
** EPITECH PROJECT, 2021
** init_all
** File description:
** init struct
*/

#include "../include/my.h"
#include "../include/objet.h"

void create_sprite(animation_t *ani)
{
    sfTexture *texture = sfTexture_createFromFile("Ennemies/GreyEnnemie.png", \
                                                &(sfIntRect) {0, 0, 303, 385});

    ani->r_enemies = (sfIntRect) {0, 0, 303, 385};
    ani->enemies = sfSprite_create();
    sfSprite_setTexture(ani->enemies, texture, sfTrue);
    sfSprite_setPosition(ani->enemies, (sfVector2f) {-100, 50});
    sfSprite_setScale(ani->enemies, (sfVector2f) {0.4, 0.4});
    return;
}

void init_window(animation_t *ani)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfTexture *texture = sfTexture_createFromFile("Map/map.jpg", \
                                    &(sfIntRect) {0, 0, 900, 661});

    ani->window = sfRenderWindow_create(mode, "My_Defender", \
                                        sfDefaultStyle, NULL);
    if (!ani->window) return;
    ani->back = sfSprite_create();
    sfSprite_setTexture(ani->back, texture, sfFalse);
    sfSprite_setScale(ani->back, (sfVector2f) {2.2, 1.6});
    sfRenderWindow_setFramerateLimit(ani->window, 30);
    sfRenderWindow_setVerticalSyncEnabled(ani->window, sfTrue);
}

void create_menu(menu_t *menu)
{
    sfTexture *texture;

    menu->back = sfSprite_create();
    texture = sfTexture_createFromFile("m.png", &(sfIntRect) {0, 0, 900, 674});
    sfSprite_setTexture(menu->back, texture, sfFalse);
    sfSprite_setScale(menu->back, (sfVector2f) {2.2, 1.6});
    free(texture);
}

void set_text_of_tower(tower_t *tower)
{
    sfFont *font;
    int price[] = {300, 600, 900, 1200};

    font = sfFont_createFromFile("font.ttf");
    for (int i = 0; i < 4; i++) {
        tower->price[i] = sfText_create();
        sfText_setString(tower->price[i], my_int_to_str(price[i]));
        sfText_setFont(tower->price[i], font);
        sfText_setStyle(tower->price[i], sfTextBold);
        sfText_setColor(tower->price[i], sfRed);
        sfText_setScale(tower->price[i], (sfVector2f) {1.5, 1.5});
    }
    sfText_setPosition(tower->price[0], (sfVector2f) {250, 700});
    sfText_setPosition(tower->price[1], (sfVector2f) {520, 700});
    sfText_setPosition(tower->price[2], (sfVector2f) {250, 950});
    sfText_setPosition(tower->price[3], (sfVector2f) {520, 950});
}

void init_struct(animation_t *ani)
{
    ani->status_game = 0;
    ani->menu->status_music = 0;
    ani->money = 500;
    ani->clock = sfClock_create();
    ani->tower->grab = -1;
    init_window(ani);
    create_sprite(ani);
    create_menu(ani->menu);
    create_all_tower(ani);
    create_song(ani);
    set_text_of_tower(ani->tower);
    load_position_for_tower(ani);
}