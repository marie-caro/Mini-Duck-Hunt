/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** duck.c
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <stddef.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/my_framebuffer.h"
void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (offset != 0)
        rect->left += 123;
    if (rect->left >= max_value)
        rect->left = 0;
}

all_t make_time_pos(all_t all, int j)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(all.clock);
    seconds = time.microseconds / (1000000.0 / (j / 5 + 1));
    if (seconds > 0.15) {
        sfSprite_setPosition(all.scene.duck.sprite, all.scene.duck.position);
        move_rect(&all.scene.duck.rect, all.scene.duck.offset, 369);
        sfClock_restart(all.clock);
        if (all.scene.duck.position.x >= 1920)
            all.scene.duck.position.x = 0;
        else {
            all.scene.duck.position.x += 100;
        }
    }
    return all;
}

sfIntRect assign_values(sfIntRect rect)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = 123;
    rect.height = 123;
    return rect;
}

all_t *output_pos(all_t *all, int *i)
{
    if (*i % 2 == 0)
        all->scene.duck.position.y = 300;
    if (*i % 3 == 0) {
        all->scene.duck.position.y = 900;
    }
    if (*i % 2 != 0)
        all->scene.duck.position.y = 550;
    if (all->scene.duck.vida == 1) {
        (*i)++;
        all->scene.duck.position.x = -5;
        all->scene.duck.vida = 0;
        all->scene.duck.position.y = 100;
    }
    return all;
}
