/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** my.h
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
#include <stdlib.h>
#include "../include/my_framebuffer.h"
#include <SFML/Audio.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *arr = malloc(sizeof(framebuffer_t));

    arr->width = width;
    arr->height = height;
    return arr;
}

void framebuffer_destroy(framebuffer_t *arr)
{
    if (arr)
    free(arr);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void destroy_everything2(all_t all, menu_t menu)
{
    sfTexture_destroy(all.scene.menu.texture);
    sfTexture_destroy(all.scene.start.texture);
    sfTexture_destroy(all.scene.quit.texture);
    close_window(menu.sys.wd);
}

int destroy_everything(all_t all, menu_t menu)
{
    sfTexture_destroy(all.scene.duck.texture);
    sfTexture_destroy(all.scene.backgr.texture);
    sfTexture_destroy(all.scene.home.texture);
    sfTexture_destroy(menu.scene.texture);
    sfTexture_destroy(menu.behind.texture);
    sfTexture_destroy(menu.button.texture);
    close_window(all.sys.wd);
    destroy_everything2(all, menu);
    return 0;
}
