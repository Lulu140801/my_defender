/*
** EPITECH PROJECT, 2021
** sort_event.c
** File description:
** sort_event
*/

#include "../include/my.h"
#include "../include/objet.h"

void sort_button_menu(animation_t *ani, sfMouseButtonEvent mouse)
{
    int nb = mouse.x;
    int nb2 = mouse.y;

    if (ani->event.type != sfEvtMouseButtonPressed) return;
    if (nb >= 674 && nb2 >= 462 && nb <= 1235 && nb2 <= 567)
        ani->status_game = GAME;
    else if (nb >= 790 && nb2 >= 605 && nb <= 1120 && nb2 <= 674)
        sfRenderWindow_close(ani->window);
}

void sort_button_game(animation_t *ani, sfMouseButtonEvent mouse)
{
    if (ani->tower->grab == -1)
        select_tower(ani, sfMouse_getPositionRenderWindow(ani->window));
    if (ani->event.type != sfEvtMouseButtonPressed) return;
    if (ani->tower->grab != -1)
        reset_sort_tower(ani);
    grab_tower(ani, sfMouse_getPositionRenderWindow(ani->window));
    return;
}
