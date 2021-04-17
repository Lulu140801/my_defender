/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main of game
*/

#include "../include/my.h"
#include "../include/objet.h"

void handle_event(animation_t *ani)
{
    while (sfRenderWindow_pollEvent(ani->window, &ani->event)) {
        if (ani->event.type == sfEvtClosed)
            sfRenderWindow_close(ani->window);
        switch (ani->status_game) {
            case MENU:
                sort_button_menu(ani, ani->event.mouseButton);
                break;
            case GAME:
                sort_button_game(ani, ani->event.mouseButton);
                break;
            default:
                break;
        }
    }
}

void display(animation_t *ani)
{
    sfRenderWindow_display(ani->window);
    switch (ani->status_game) {
        case GAME:
            verif_music_game(ani);
            display_game(ani);
            break;
        case MENU:
            verif_music_menu(ani);
            display_menu(ani);
            break;
        default:
            break;
    }
}

void game_loop(animation_t *ani)
{
    while (sfRenderWindow_isOpen(ani->window)) {
        ani->time = sfClock_getElapsedTime(ani->clock);
        ani->seconds = ani->time.microseconds / 1000000.0;
        display(ani);
        handle_event(ani);
    }
    destroy_music(ani);
}

int main(void)
{
    animation_t ani;
    menu_t menu;
    tower_t tower;

    ani.menu = &menu;
    ani.tower = &tower;
    init_struct(&ani);
    game_loop(&ani);
    sfRenderWindow_destroy(ani.window);
    return (0);
}