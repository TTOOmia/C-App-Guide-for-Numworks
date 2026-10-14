#include "libs/eadk.h"
#include "libs/storage.h"
#include "libs/macro.h"

#include "typedefs.h"
#include "include/renderWindow.h"

#define SCREEN_HEIGHT 240
#define SCREEN_WIDTH 320

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Test";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

Player player = {
    (Vector2){0U, 0U},
    0U,
    0U
};
static Vector2 oldPos = {0U, 0U};

enum {FPS = 30};
clear(eadk_color_white);

int main(void) {
    while (1) {
        eadk_keyboard_state_t state = eadk_keyboard_scan();

        if (eadk_keyboard_key_down(state, eadk_key_back)) break;

        if (eadk_keyboard_key_down(state, eadk_key_right)) {
            player.pos.x += 5;
        }
        if (eadk_keyboard_key_down(state, eadk_key_left)) {
            player.pos.x -= 5;
        }
        // if (eadk_keyboard_key_down(state, eadk_key_down)) {
        //     player.y += 5;
        // }
        // if (eadk_keyboard_key_down(state, eadk_key_up)) {
        //     player.y -= 5;
        // }

        if (player.pos.y < SCREEN_HEIGHT - 10){
            player.yspd++;
        } else {
            player.pos.y = SCREEN_HEIGHT - 10;
            player.yspd = 0;
            if (eadk_keyboard_key_down(state, eadk_key_ok)){
                player.yspd = -10;
            }
        }

        player.pos.y += player.yspd;

        eadk_display_wait_for_vblank();
        renderRect(oldPos, 10, 10, eadk_color_white);
        renderRect((Vector2){player.pos.x, player.pos.y}, 10, 10, eadk_color_blue);
        oldPos = player.pos;
        eadk_display_wait_for_vblank();
        eadk_timing_msleep(1000u/FPS);
    }
    return 0;
}
