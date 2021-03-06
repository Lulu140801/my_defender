/*
** EPITECH PROJECT, 2021
** manage_sound.c
** File description:
** manage_sound
*/

#include "my.h"
#include "objet.h"

int create_song(animation_t *ani)
{
    ani->music = sfMusic_createFromFile("music1.ogg");
    if (!ani->music)
        return (84);
    ani->menu->music = sfMusic_createFromFile("music2.ogg");
    if (!ani->menu->music)
        return (84);
    sfMusic_play(ani->menu->music);
    sfMusic_setLoop(ani->music, sfTrue);
    sfMusic_setLoop(ani->menu->music, sfTrue);
    ani->menu->status_music = 1;
    return (0);
}

void verif_music_game(animation_t * ani)
{
    if (ani->menu->status_music == 1) {
        ani->menu->status_music = 0;
        sfMusic_stop(ani->menu->music);
    }
    if (ani->status_music == 0) {
        ani->status_music = 1;
        sfMusic_play(ani->music);
    }
}

void verif_music_menu(animation_t *ani)
{
    sfMusic_stop(ani->music);
    if (ani->menu->status_music == 0) {
        ani->menu->status_music = 1;
        sfMusic_play(ani->menu->music);
    }
}

void destroy_music(animation_t *ani)
{
    sfMusic_destroy(ani->music);
    sfMusic_destroy(ani->menu->music);
}