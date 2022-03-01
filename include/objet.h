/*
** EPITECH PROJECT, 2020
** OBJECT_H_
** File description:
** Header for defender
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Font.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Graphics/Shape.h>
    #include <SFML/Graphics.h>

    #define MENU (0)
    #define GAME (1)
    #define LOW_TOWER (300)
    #define MID_TOWER (600)
    #define UP_TOWER (900)
    #define ULTRA_TOWER (1200)

    typedef struct
    {
        int grab;
        int place_taken;
        sfSprite *bullet[4];
        sfSprite *low_tower[3];
        int low_damage[3];
        sfSprite *mid_tower[3];
        int mid_damage[3];
        sfSprite *up_tower[3];
        int up_damage[3];
        sfSprite *ultra_tower[3];
        int ultra_damage[3];
        sfText *price[4];
        int pos[10][2];
        sfSprite *place_tower[10];
        int damage_tower[10];
    }tower_t;

    typedef struct
    {
        int status_music;
        sfSprite *back;
        sfMusic *music;
    }menu_t;

    typedef struct
    {
        int status_game;
        int money;
        int status_music;
        sfSprite *s_life;
        int life;
        sfEvent event;
        sfRenderWindow *window;
        sfSprite *back;
        sfSprite *enemies;
        sfIntRect r_enemies;
        sfClock *clock;
        sfTime time;
        sfMusic *music;
        float seconds;
        sfVector2f pos_ini;
        menu_t *menu;
        tower_t *tower;
    } animation_t;

    int game_song(animation_t *ms);
    void animation_enemies(animation_t *ani);
    int init_struct(animation_t *ani);
    void mouv_sprite(animation_t *ani);
    void display_game(animation_t *ani);
    void sort_button_menu(animation_t *ani, sfMouseButtonEvent mouse);
    void display_menu(animation_t *ani);
    void sort_button_game(animation_t *ani);
    int create_all_tower(animation_t *ani);
    int create_song(animation_t *ani);
    void verif_music_game(animation_t * ani);
    void verif_music_menu(animation_t *ani);
    void destroy_music(animation_t *ani);
    void load_position_for_tower(animation_t *ani);
    void update_color_text(animation_t *ani);
    void select_tower(animation_t * ani, sfVector2i pos_mouse);
    void grab_sort_tower(animation_t *ani);
    void grab_tower(animation_t *ani, sfVector2i pos_mouse);
    void reset_sort_tower(animation_t *ani);
    void set_tower_pos(animation_t *ani, sfVector2i pos_mouse);
    void animate_the_enemies(sfSprite *enemy, animation_t *ani);
    int init_life(animation_t *ani);
    void remove_life(animation_t *ani);
#endif /* OBJECT_H_ */