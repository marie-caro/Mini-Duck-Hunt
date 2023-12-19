/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** my_hunter.c
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
#include <SFML/Audio.h>
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
#include <stdlib.h>
#include "../include/my_framebuffer.h"
#include "../lib/my/my.h"

gameobject_t behind_ctor(void)
{
    gameobject_t behind;

    behind.sprite = sfSprite_create();
    behind.texture = sfTexture_createFromFile("Sprites/duckhunt.png", NULL);
    sfSprite_setTexture(behind.sprite, behind.texture, sfTrue);
    behind.position.x = 550;
    behind.position.y = 250;
    sfSprite_setPosition(behind.sprite, behind.position);
    return behind;
}

gameobject_t button_ctor(void)
{
    gameobject_t button;

    button.sprite = sfSprite_create();
    button.texture = sfTexture_createFromFile("Sprites/start.png", NULL);
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    button.position.x = 840;
    button.position.y = 650;
    sfSprite_setPosition(button.sprite, button.position);
    return button;
}

menu_t menu_ctor(sfEvent event)
{
    menu_t menu;
    sfVideoMode video_mode = {1920, 1080, 32};

    menu.isoff = 0;
    menu.error = 0;
    menu.sys.wd = sfRenderWindow_create(video_mode, "My_Hunter", sfResize
    | sfClose, NULL);
    menu.sys.event = event;
    menu.scene.sprite = sfSprite_create();
    menu.scene.texture = sfTexture_createFromFile("Sprites/FOREST.png", NULL);
    sfSprite_setTexture(menu.scene.sprite, menu.scene.texture, sfTrue);
    menu.behind = behind_ctor();
    menu.button = button_ctor();
    return menu;
}

menu_t *is_menu(menu_t *menu)
{
    sfRenderWindow_setMouseCursorVisible(menu->sys.wd, sfTrue);
    while (sfRenderWindow_isOpen(menu->sys.wd)) {
        sfRenderWindow_clear(menu->sys.wd, sfBlack);
        if (menu->isoff == 1)
            return menu;
        sfRenderWindow_drawSprite(menu->sys.wd, menu->scene.sprite, NULL);
        sfRenderWindow_drawSprite(menu->sys.wd, menu->behind.sprite, NULL);
        sfRenderWindow_drawSprite(menu->sys.wd, menu->button.sprite, NULL);
        while (sfRenderWindow_pollEvent(menu->sys.wd, &menu->sys.event))
            menu = analyse_menu(menu->sys.event, menu);
        if (menu->error == 84)
            return menu;
        sfRenderWindow_display(menu->sys.wd);
    }
    return menu;
}

sys_t sys_ctor(sfEvent event, menu_t menu)
{
    sys_t sys;

    sys.wd = menu.sys.wd;
    sys.event = event;
    return sys;
}
