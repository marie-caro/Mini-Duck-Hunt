/*
** EPITECH PROJECT, 2023
** GOOD_VER
** File description:
** ctor_mouse.c
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

gameobject_t mouse_ctor(void)
{
    gameobject_t mouse;
    sfIntRect rect;

    mouse.sprite = sfSprite_create();
    mouse.texture = sfTexture_createFromFile("Sprites/target .png", NULL);
    sfSprite_setTexture(mouse.sprite, mouse.texture, sfTrue);
    mouse.rect = assign_values(rect);
    mouse.position.x = 1620;
    mouse.position.y = 32;
    sfSprite_setPosition(mouse.sprite, mouse.position);
    mouse.offset = 0;
    mouse.vida = 0;
    return mouse;
}

all_t *change_mouse(all_t *all)
{
    sfFloatRect Bounds = sfSprite_getGlobalBounds(all->scene.mouse.sprite);
    sfVector2f origin = {Bounds.width / 2, Bounds.height / 2};
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(all->sys.wd);
    sfVector2f Position = {(float)mousePosition.x, (float)mousePosition.y};

    sfSprite_setTexture(all->scene.mouse.sprite, all->scene.mouse.texture, sfTrue);
    sfSprite_setOrigin(all->scene.mouse.sprite, origin);
    sfSprite_setPosition(all->scene.mouse.sprite, Position);
    sfRenderWindow_drawSprite(all->sys.wd, all->scene.mouse.sprite, NULL);
    return all;
}

// From ctor_pause.c
void too_many_pause(all_t *all)
{
    sfRenderWindow_drawSprite(all->sys.wd, all->scene.duck.sprite, NULL);
}

// From ctor.c
mytext_t text_ctor(sfVector2f textPosition, int pos, sfColor color)
{
    mytext_t text;

    text.text = sfText_create();
    text.font = sfFont_createFromFile("Fonts/Valoon.ttf");
    sfText_setFont(text.text, text.font);
    sfText_setCharacterSize(text.text, pos);
    sfText_setPosition(text.text, textPosition);
    sfText_setColor(text.text, color);
    return text;
}
