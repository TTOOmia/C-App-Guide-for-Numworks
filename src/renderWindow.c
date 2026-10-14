#include "include/renderWindow.h"
#include "typedefs.h"
#include "libs/eadk.h"

void renderRect(Vector2 pos, int height, int width, eadk_color_t color){
    eadk_rect_t rect = {
        pos.x,
        pos.y,
        height,
        width
    };
    eadk_display_push_rect_uniform(rect, color);
}

void clear(eadk_color_t color){
    eadk_display_push_rect_uniform(eadk_screen_rect, color);
}