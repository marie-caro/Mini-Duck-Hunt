/*
** EPITECH PROJECT, 2023
** GOOD_VER
** File description:
** ctor_->c
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

gameobject_t pause_menu_ctor(void)
{
    gameobject_t menu;

    menu.sprite = sfSprite_create();
    menu.texture = sfTexture_createFromFile("Sprites/menu.png", NULL);
    sfSprite_setTexture(menu.sprite, menu.texture, sfTrue);
    menu.position.x = 475;
    menu.position.y = 150;
    sfSprite_setPosition(menu.sprite, menu.position);
    return menu;
}

gameobject_t music_ctor(void)
{
    gameobject_t music;

    music.sprite = sfSprite_create();
    music.texture = sfTexture_createFromFile("Sprites/music.png", NULL);
    sfSprite_setTexture(music.sprite, music.texture, sfTrue);
    music.position.x = 950;
    music.position.y = 350;
    sfSprite_setPosition(music.sprite, music.position);
    return music;
}

gameobject_t restart_ctor(void)
{
    gameobject_t restart;

    restart.sprite = sfSprite_create();
    restart.texture = sfTexture_createFromFile("Sprites/restart.png", NULL);
    sfSprite_setTexture(restart.sprite, restart.texture, sfTrue);
    restart.position.x = 950;
    restart.position.y = 550;
    sfSprite_setPosition(restart.sprite, restart.position);
    return restart;
}

gameobject_t quit_ctor(void)
{
    gameobject_t quit;

    quit.sprite = sfSprite_create();
    quit.texture = sfTexture_createFromFile("Sprites/quit.png", NULL);
    sfSprite_setTexture(quit.sprite, quit.texture, sfTrue);
    quit.position.x = 960;
    quit.position.y = 750;
    sfSprite_setPosition(quit.sprite, quit.position);
    return quit;
}
