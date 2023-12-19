/*
** EPITECH PROJECT, 2023
** GOOD_VER
** File description:
** main.c
*/
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my_framebuffer.h"
#include "../lib/my/my.h"
#include <SFML/Audio.h>

int choose_screen(menu_t *menu, all_t *all)
{
    if (menu->error == 84) {
        return 84;
    }
    if (menu->isoff == 3) {
        menu = is_menu(menu);
    }
    if (menu->isoff == 2) {
        game_loop(all, menu);
    }
    if (menu->isoff == 5) {
        if (stop_loop(all, menu) == 84)
            return 84;
    }
    return 0;
}

void start_game(void)
{
    sfEvent event;
    all_t all;
    menu_t *menu = malloc(sizeof(menu_t));

    *menu = menu_ctor(event);
    menu = is_menu(menu);
    if (menu->error == 84)
        return;
    if (menu->isoff == 2)
        return;
    all = all_ctor(event, *menu);
    all.j = 0;
    if (game_loop(&all, menu) == 84)
        return;
    return;
}

int main(int ac, char **av)
{
    if (ac == 0)
        return 84;
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == true)
            output_help();
        return 84;
    }
    if (ac > 2)
        return 84;
    start_game();
    return 0;
}
