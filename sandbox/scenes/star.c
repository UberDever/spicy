//
// Created by uberdever on 15.08.2020.
//
#if 0
#include "../scene.h"

static uint frames = 0;
static v2* vec_points = NULL;

static const uint flares = 6 * 2;
static const float32 inner_rad = 1.5;
static const float32 outer_rad = 3;
static const v2 star_pos;
static const v2 star_size = {300, 300};
static const float32 rot_speed = DEG2RAD(180.f / 60);
static const m2 rot_star_mat;
static bool is_rotating = true;

void init(void) {
    vec_new(vec_points, flares);
    pi_v2(star_pos, g_scr.w / 2, g_scr.h / 2);
    pi_m2_rotation(rot_star_mat, rot_speed);
    const float32 ang = DEG2RAD(360.f / (flares / 2));
    const m2 rot_mat;
    pi_m2_rotation(rot_mat, ang);
    v2 point_start_inner = {0, 1 * outer_rad};
    v2 point_start_outer = {0, 1 * inner_rad};
    pi_v2_rotate(point_start_inner, -ang / 2, point_start_inner);
    for (uint i = 0; i < flares; i++)
    {
        if (i % 2)
        {
            vec_push(vec_points, point_start_outer);
            pi_v2_mul_m2(rot_mat, point_start_outer, point_start_outer);
        } else
        {
            vec_push(vec_points, point_start_inner);
            pi_v2_mul_m2(rot_mat, point_start_inner, point_start_inner);
        }
    }
    for (uint i = 0; i < flares; i++)
    {
        pi_v2_muls(vec_points[i], star_size[0] / (2 * outer_rad), vec_points[i]);
    }
}

void begin_frame(void) {
    g_screen_clear();
    g_screen_buffer_clear();
}

void end_frame(void) {
    g_screen_buffer_update();
    g_screen_present();
}

void event_handler(void)
{
    if (kbd_key_pushed(SDLK_SPACE))
    {
        is_rotating = !is_rotating;
    }
    if (kbd_key_pushed(SDLK_q))
    {

    }
}

void update(void) {

}

void render(void) {
    g_screen_draw_number(5, 5, frames, COLOR(yellow));
    for (uint i = 0; i < (flares); i++)
    {
        is_rotating ? pi_v2_mul_m2(rot_star_mat, vec_points[i], vec_points[i]) : 0;
    }
    for (uint i = 0; i < (flares); i++)
    {
        v2 point0;
        v2 point1;
        pi_v2_add(vec_points[i], star_pos, point0);
        pi_v2_add(vec_points[(i + 1) % (flares)], star_pos, point1);
        g_screen_draw_line( point0[0], point0[1],
                            point1[0], point1[1],
                            COLOR(blue));
    }
    frames++;
    if (frames > 60) frames = 0;
}

void clean(void) {
    vec_free(vec_points);
}
#endif

