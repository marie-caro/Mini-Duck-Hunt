/*
** EPITECH PROJECT, 2023
** GOOD_VER
** File description:
** ctor_pause.c
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

gameobject_t pause_ctor(void)
{
    gameobject_t pause;
    sfIntRect rect;

    pause.sprite = sfSprite_create();
    pause.texture = sfTexture_createFromFile("Sprites/pause.png", NULL);
    sfSprite_setTexture(pause.sprite, pause.texture, sfTrue);
    pause.rect = assign_values(rect);
    pause.position.x = 1620;
    pause.position.y = 32;
    sfSprite_setPosition(pause.sprite, pause.position);
    pause.offset = 0;
    pause.vida = 0;
    return pause;
}

all_t *game_loop_pause2(all_t *all)
{
    sfSprite_setTextureRect(all->scene.music.sprite, all->scene.music.rect);
    sfSprite_setTextureRect(all->scene.start.sprite, all->scene.start.rect);
    sfSprite_setTextureRect(all->scene.quit.sprite, all->scene.quit.rect);
    change_mouse(all);
    return all;
}

all_t *game_loop_pause(all_t *all, menu_t *menu)
{
    char *str = malloc(sizeof(char) * 20);

    str = "SCORE: ";
    while (sfRenderWindow_pollEvent(all->sys.wd, &all->sys.event))
        all = analyse_events(all->sys.event, all, menu);
    if (all->error == 84)
        return all;
    sfRenderWindow_clear(all->sys.wd, sfBlack);
    sfRenderWindow_drawSprite(all->sys.wd, all->scene.backgr.sprite, NULL);
    sfText_setString(all->scene.text.text, my_strcat(str, tostr(all->j)));
    sfSprite_setTextureRect(all->scene.duck.sprite, all->scene.duck.rect);
    sfSprite_setTextureRect(all->scene.duck.sprite, all->scene.duck.rect);
    sfSprite_setTextureRect(all->scene.menu.sprite, all->scene.menu.rect);
    sfSprite_setTextureRect(all->scene.pause.sprite, all->scene.pause.rect);
    sfSprite_setTextureRect(all->scene.home.sprite, all->scene.home.rect);
    sfSprite_setTextureRect(all->scene.menu.sprite, all->scene.menu.rect);
    all = game_loop_pause2(all);
    sfRenderWindow_drawSprite(all->sys.wd, all->scene.home.sprite, NULL);
    sfRenderWindow_drawText(all->sys.wd, all->scene.text.text, NULL);
    return all;
}

int stop_loop(all_t *all, menu_t *menu)
{
    sfVector2u textureSize = sfTexture_getSize(all->scene.menu.texture);
    sfVector2u textureTize = sfTexture_getSize(all->scene.quit.texture);

    sfRenderWindow_setMouseCursorVisible(menu->sys.wd, sfTrue);
    sfRenderWindow_setFramerateLimit(all->sys.wd, 60);
    while (sfRenderWindow_isOpen(all->sys.wd)) {
        if (game_loop_pause(all, menu)->error == 84)
            return 84;
        if (all->scene.duck.vida == 0)
            too_many_pause(all);
        all->scene.menu.rect = (sfIntRect){0, 0, textureSize.x, textureSize.y};
        all->scene.quit.rect = (sfIntRect){0, 0, textureTize.x, textureTize.y};
        sfRenderWindow_drawSprite(all->sys.wd, all->scene.menu.sprite, NULL);
        sfRenderWindow_drawSprite(all->sys.wd, all->scene.quit.sprite, NULL);
        sfRenderWindow_drawSprite(all->sys.wd, all->scene.pause.sprite, NULL);
        sfRenderWindow_drawSprite(all->sys.wd, all->scene.music.sprite, NULL);
        sfRenderWindow_drawSprite(all->sys.wd, all->scene.start.sprite, NULL);
        sfRenderWindow_display(all->sys.wd);
    }
    return 0;
}
