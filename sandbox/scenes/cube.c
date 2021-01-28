//
// Created by uberdever on 11.08.2020.
//
#if 0
#include "../scene.h"

static uint frames = 0;
static float32 angle_x = 0;
static float32 angle_y = 0;
static float32 angle_z = 0;
static float32 z_offset = 2;
static const float32 rot_speed = 0.055;

static m3 rotation_matrix;
static TriangleList list;
static tex texture;

void init(void)
{
    color arr[] = {COLOR(red), COLOR(green), COLOR(blue), COLOR(cyan),
                   COLOR(magenta), COLOR(white), COLOR(yellow), COLOR(orange)};
    trianglelist_new(&list, 14, 36);
    shape_cube_triangles_textured(&list, 1);
    for (uint i = 0; i < ARR_ONE_DIM_LEN(arr); i++)
    {
        COLOR2FLOAT(arr[i], list.vert[i].c);
    }
    texture.surf = IMG_Load("../resources/tnt_side.png");
    if (!texture.surf)
        error("Can't load png texture");
    texture.size[0] = texture.surf->w / 1;
    texture.size[1] = texture.surf->h / 1;
    pipeline_bind_texture(texture);
}

void begin_frame(void)
{
    g_screen_clear();
    g_screen_buffer_clear();
}

void end_frame(void)
{
    g_screen_buffer_update();
    g_screen_present();
}

void event_handler(void)
{
    if (kbd_key_pressed(SDLK_w))
    {
        angle_x = (angle_x - rot_speed);
    }
    if (kbd_key_pressed(SDLK_a))
    {
        angle_y = (angle_y - rot_speed);
    }
    if (kbd_key_pressed(SDLK_s))
    {
        angle_x = (angle_x + rot_speed);
    }
    if (kbd_key_pressed(SDLK_d))
    {
        angle_y = (angle_y + rot_speed);
    }
    if (kbd_key_pressed(SDLK_q))
    {
        angle_z = (angle_z + rot_speed);
    }
    if (kbd_key_pressed(SDLK_e))
    {
        angle_z = (angle_z - rot_speed);
    }
    if (kbd_key_pushed(SDLK_r))
    {
    }
    if (kbd_key_pressed(SDLK_z))
    {
        z_offset -= .01;
    }
    if (kbd_key_pressed(SDLK_c))
    {
        z_offset += .01;
    }
    angle_x = wrap_angle(angle_x);
    angle_y = wrap_angle(angle_y);
    angle_z = wrap_angle(angle_z);
}

void update(void)
{
}

void render_axis()
{
    const v3 axis_o = {g_scr.w / 2, g_scr.h / 2, z_offset};
    m3 axis;
    pi_m3_identity(axis);
    v3 cross;
    pi_v3(cross, 0, 0, 1);
    axis[2][0] = cross[0], axis[2][1] = cross[1], axis[2][2] = cross[2];
    pi_m3_mul_m3(rotation_matrix, axis, axis);
    axis[0][2] += z_offset;
    axis[1][2] += z_offset;
    axis[2][2] += z_offset;
    ndc_transform(axis[0], g_scr.w, g_scr.h, axis[0]);
    ndc_transform(axis[1], g_scr.w, g_scr.h, axis[1]);
    ndc_transform(axis[2], g_scr.w, g_scr.h, axis[2]);
    g_screen_draw_line(axis_o[0], axis_o[1], axis[0][0], axis[0][1], COLOR(red));
    g_screen_draw_line(axis_o[0], axis_o[1], axis[1][0], axis[1][1], COLOR(green));
    g_screen_draw_line(axis_o[0], axis_o[1], axis[2][0], axis[2][1], COLOR(blue));
}

void render_normal(const v3 v0, const v3 v1, const v3 v2, v3 normal)
{
    v3 np = {v0[0] + v1[0] + v2[0],
             v0[1] + v1[1] + v2[1],
             v0[2] + v1[2] + v2[2]};
    pi_v3_divs(np, 3, np);
    pi_v3_add(normal, np, normal);
    pi_v3_normalize(normal, normal);
    ndc_transform(np, g_scr.w, g_scr.h, np);
    ndc_transform(normal, g_scr.w, g_scr.h, normal);
    g_screen_draw_line(np[0], np[1], normal[0], normal[1], COLOR(cyan));
}

void render(void)
{
    g_screen_fill((color){.r = 0, .g = 0, .b = 64, .a = 0});
    g_screen_draw_number(5, 5, frames, COLOR(yellow));
    frames++;
    if (frames > 60)
        frames = 0;

    m3 rotX, rotY, rotZ;
    pi_m3_rotationX(rotX, angle_x);
    pi_m3_rotationY(rotY, angle_y);
    pi_m3_rotationZ(rotZ, angle_z);
    pi_m3_mul_m3(rotY, rotX, rotX);
    pi_m3_mul_m3(rotZ, rotX, rotation_matrix);

    pipeline_bind_rotation(rotation_matrix);
    pipeline_bind_translation((v3){0, 0, z_offset});

    pipeline_draw(&list);
    render_axis();
}

void clean(void)
{
    trianglelist_free(&list);
}
#endif