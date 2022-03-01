/*
** EPITECH PROJECT, 2021
** init_all
** File description:
** init struct
*/

#include "my.h"
#include "objet.h"

int create_sprite(animation_t *ani)
{
    sfTexture *texture = sfTexture_createFromFile("Ennemies/GreyEnnemie.png", \
                                                &(sfIntRect) {0, 0, 303, 385});

    if (!texture)
        return (84);
    ani->r_enemies = (sfIntRect) {0, 0, 303, 385};
    ani->enemies = sfSprite_create();
    sfSprite_setTexture(ani->enemies, texture, sfTrue);
    sfSprite_setPosition(ani->enemies, (sfVector2f) {-100, 120});
    sfSprite_setOrigin(ani->enemies, (sfVector2f) {150, 192});
    sfSprite_setScale(ani->enemies, (sfVector2f) {0.4, 0.4});
    return (0);
}

int init_window(animation_t *ani)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfTexture *texture = sfTexture_createFromFile("Map/map.jpg", \
                                    &(sfIntRect) {0, 0, 900, 661});

    if (!texture)
        return (84);
    ani->window = sfRenderWindow_create(mode, "My_Defender", \
                                        sfDefaultStyle, NULL);
    if (!ani->window)
        return (84);
    ani->back = sfSprite_create();
    sfSprite_setTexture(ani->back, texture, sfFalse);
    sfSprite_setScale(ani->back, (sfVector2f) {2.2, 1.6});
    sfRenderWindow_setFramerateLimit(ani->window, 30);
    sfRenderWindow_setVerticalSyncEnabled(ani->window, sfTrue);
    ani->clock = sfClock_create();
    ani->status_game = 0;
    ani->money = 500;
    return (0);
}

int create_menu(menu_t *menu)
{
    sfTexture *texture;

    menu->back = sfSprite_create();
    texture = sfTexture_createFromFile("m.png", &(sfIntRect) {0, 0, 900, 674});
    if (!texture)
        return (84);
    sfSprite_setTexture(menu->back, texture, sfFalse);
    sfSprite_setScale(menu->back, (sfVector2f) {2.2, 1.6});
    free(texture);
    return (0);
}

int set_text_of_tower(animation_t *ani)
{
    sfFont *font;
    int price[] = {300, 600, 900, 1200};

    font = sfFont_createFromFile("font.ttf");
    if (!font)
        return (84);
    for (int i = 0; i < 4; i++) {
        ani->tower->price[i] = sfText_create();
        sfText_setString(ani->tower->price[i], my_int_to_str(price[i]));
        sfText_setFont(ani->tower->price[i], font);
        sfText_setStyle(ani->tower->price[i], sfTextBold);
        sfText_setColor(ani->tower->price[i], sfRed);
        sfText_setScale(ani->tower->price[i], (sfVector2f) {1.5, 1.5});
    }
    sfText_setPosition(ani->tower->price[0], (sfVector2f) {250, 700});
    sfText_setPosition(ani->tower->price[1], (sfVector2f) {520, 700});
    sfText_setPosition(ani->tower->price[2], (sfVector2f) {250, 950});
    sfText_setPosition(ani->tower->price[3], (sfVector2f) {520, 950});
    load_position_for_tower(ani);
    return (0);
}

int init_struct(animation_t *ani)
{
    if (init_window(ani) == 84)
        return (84);
    if (create_sprite(ani) == 84)
        return (84);
    if (create_menu(ani->menu) == 84)
        return (84);
    if (create_all_tower(ani) == 84)
        return (84);
    if (set_text_of_tower(ani) == 84)
        return (84);
    if (create_song(ani) == 84)
        return (84);
    if (init_life(ani) == 84)
        return (84);
    return (0);
}