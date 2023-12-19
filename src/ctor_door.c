/*
** EPITECH PROJECT, 2023
** GOOD_VER
** File description:
** ctor_door.c
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
#include <SFML/Audio.h>
#include <stdbool.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <SFML/Audio/Music.h>
#include "../include/my_framebuffer.h"
#include "../lib/my/my.h"
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

gameobject_t open_ctor(void)
{
    gameobject_t open;

    open.sprite = sfSprite_create();
    open.texture = sfTexture_createFromFile("Sprites/open.png", NULL);
    sfSprite_setTexture(open.sprite, open.texture, sfTrue);
    open.position.x = 1650;
    open.position.y = 900;
    sfSprite_setPosition(open.sprite, open.position);
    return open;
}

gameobject_t close_ctor(void)
{
    gameobject_t close;

    close.sprite = sfSprite_create();
    close.texture = sfTexture_createFromFile("Sprites/close.png", NULL);
    sfSprite_setTexture(close.sprite, close.texture, sfTrue);
    close.position.x = 1650;
    close.position.y = 900;
    sfSprite_setPosition(close.sprite, close.position);
    return close;
}
