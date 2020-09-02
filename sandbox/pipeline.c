//
// Created by uberdever on 21.08.2020.
//

#include "pipeline.h"

static m3 rotation;
static v3 translation;
static tex texture;
bool is_texture_bound = false;

void pipeline_bind_rotation(m3 rot) {pi_m3_copy(rot, rotation);}
void pipeline_bind_translation(v3 trans) {pi_v3_copy(trans, translation);}
void pipeline_bind_texture(tex texture_) {texture = texture_; is_texture_bound = true;}

void assemble_triangles(vx* vert_in, const uint* ind_in);
void geometry_shader(vx v0_in, vx v1_in, vx v2_in);
void ndc_transformer(vx vx0, vx vx1, vx vx2);
void draw_triangle(vx vx0, vx vx1, vx vx2);

void transform_vertices(vx* vert_in, uint* ind_in)
{
    vx* vert_out = NULL;
    arr_copy_contents(vert_in, vert_out, vec);
    const uint size = vec_get_size(vert_out);
    for (uint i = 0; i < size; i++)
    {
        pi_v3_mul_m3(rotation, vert_out[i].p, vert_out[i].p);
        pi_v3_add(translation, vert_out[i].p, vert_out[i].p);
    }
    assemble_triangles(vert_out, ind_in);
}

void assemble_triangles(vx* vert_in, const uint* ind_in)
{
    const uint size = vec_get_size(ind_in);
    for (uint i = 0; i < size; i+=3)
    {
        geometry_shader(vert_in[ind_in[i]], vert_in[ind_in[i + 1]], vert_in[ind_in[i + 2]]);
    }
}

void geometry_shader(vx v0_in, vx v1_in, vx v2_in)
{
    // insert geometry shader here //
    vx v0_out, v1_out, v2_out;
    memcpy(&v0_out, &v0_in, sizeof(vx));
    memcpy(&v1_out, &v1_in, sizeof(vx));
    memcpy(&v2_out, &v2_in, sizeof(vx));
    // insert geometry shader here //
    // Back-face culling
    v3 vec0, vec1;
    pi_v3(vec0, v1_out.p[0] - v0_out.p[0], v1_out.p[1] - v0_out.p[1], v1_out.p[2] - v0_out.p[2]);
    pi_v3(vec1, v2_out.p[0] - v0_out.p[0], v2_out.p[1] - v0_out.p[1], v2_out.p[2] - v0_out.p[2]);
    v3 cross_product;
    pi_v3_cross(vec1, vec0, cross_product);
    if (pi_v3_dot(cross_product, v0_out.p) <= 0)
    {
        ndc_transformer(v0_out, v1_out, v2_out);
    }
}

void ndc_transformer(vx vx0, vx vx1, vx vx2)
{
    ndc_transform(vx0.p, g_scr.w, g_scr.h, vx0.p);
    ndc_transform(vx1.p, g_scr.w, g_scr.h, vx1.p);
    ndc_transform(vx2.p, g_scr.w, g_scr.h, vx2.p);
    draw_triangle(vx0, vx1, vx2);
}

static Uint32 get_pixel(int x, int y)
{
    int bpp = texture.surf->format->BytesPerPixel;
    Uint8 *p = (Uint8 *) texture.surf->pixels + (y * texture.surf->pitch) + x * bpp;

    switch (bpp) {
        case 1:
            return *p;
        case 2:
            return *(Uint16 *) p;
        case 3: {
            const Uint32 tmp = p[0] | p[1] << 8 | p[2] << 16;
            return tmp;
        }
        case 4:
            return *(Uint32 *) p;
        default:
            return 0;       /* shouldn't happen, but avoids warnings */
    }
}


#if 1
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-flp30-c"
void draw_flat_triangle(vx vx_top, vx vx_bottom, vx dvx0, vx dvx1, vx vx_start1)
{
    vx vx_start0 = vx_top;
    const int p_sy = (int)(ceilf(vx_top.p[1] - 0.5f));
    const int p_ey = (int)(ceilf(vx_bottom.p[1] - 0.5f));
    const float32 prestep = (float32)p_sy + 0.5 - vx_start0.p[1];
    vx_start0.p[0] += prestep * dvx0.p[0]; vx_start1.p[0] += prestep * dvx1.p[0];
    vx_start0.p[1] += prestep * dvx0.p[1]; vx_start1.p[1] += prestep * dvx1.p[1];
    const float dy = 1.f / (float32)(p_ey - p_sy);
    for (int y = p_sy; y < p_ey;
         y++,
         vx_start0.c.a += dvx0.c.a, vx_start1.c.a += dvx1.c.a,
         vx_start0.c.r += dvx0.c.r, vx_start1.c.r += dvx1.c.r,
         vx_start0.c.g += dvx0.c.g, vx_start1.c.g += dvx1.c.g,
         vx_start0.c.b += dvx0.c.b, vx_start1.c.b += dvx1.c.b,
         vx_start0.p[0] += dvx0.p[0], vx_start1.p[0] += dvx1.p[0])
    {
        const int p_sx = (int)ceilf(vx_start0.p[0] - 0.5f);
        const int p_ex = (int)ceilf(vx_start1.p[0] - 0.5f);

        const float32 dx = 1.f / (float32)(p_ex - p_sx);
        const vc dc = {.a = (float32)(vx_start1.c.a - vx_start0.c.a) * dx,
                       .r = (float32)(vx_start1.c.r - vx_start0.c.r) * dx,
                       .g = (float32)(vx_start1.c.g - vx_start0.c.g) * dx,
                       .b = (float32)(vx_start1.c.b - vx_start0.c.b) * dx};

        vc c = vx_start0.c;
        const float32 lerp_y = ((float32)(y - p_sy) * dy);
        v2 t0;
        pi_v2_muls(dvx0.t, lerp_y, t0);
        pi_v2_add(t0, vx_start0.t, t0);
        v2 t1;
        pi_v2_muls(dvx1.t, lerp_y, t1);
        pi_v2_add(t1, vx_start1.t, t1);

        for(int x = p_sx; x < p_ex; x++,
                                    c.a += dc.a,
                                    c.r += dc.r,
                                    c.g += dc.g,
                                    c.b += dc.b)

        {
            v2 t;
            pi_v2_sub(t1, t0, t);
            pi_v2_muls(t, ((float32)(x - p_sx) * dx), t);
            pi_v2_add(t, t0, t);
            if (!is_texture_bound)
            {
                g_screen_put_pixel(x, y, /*(color){.a = c.a * 255, .r = c.r * 255, .g = c.g * 255, .b = c.b * 255}*/ COLOR(white));
            }
            else
            {
                int t_x = t[0] * texture.size[0];
                t_x %= (texture.size[0]);
                int t_y = t[1] * texture.size[1];
                t_y %= (texture.size[1]);
                t_x = pi_clamp(t_x, 0, texture.size[0] - 1);
                t_y = pi_clamp(t_y, 0, texture.size[0] - 1);
                g_screen_put_pixel(x, y, (color){0xFF000000 + get_pixel(t_x, t_y)});
            }
        }
    }
#if 0
    vx vx_start0 = vx0;
    const int p_sy = (int)(ceilf(vx0.p[1] - 0.5f));
    const int p_ey = (int)(ceilf(vx2.p[1] - 0.5f));

    const float32 prestep = ((float32)p_sy + 0.5f - vx0.p[1]);
    const vx lerp_prestep0 = vertex_muls(dvx0, prestep);
    const vx lerp_prestep1 = vertex_muls(dvx1, prestep);
    vx_start0 = vertex_add(vx_start0, lerp_prestep0);
    vx_start1 = vertex_add(vx_start1, lerp_prestep1);
    for (int y = p_sy; y < p_ey;
         y++,
         vx_start0 = vertex_add(vx_start0, dvx0),
         vx_start1 = vertex_add(vx_start1, dvx1))
    {
        const int p_sx = (int)ceilf(vx_start0.p[0] - 0.5f);
        const int p_ex = (int)ceilf(vx_start1.p[0] - 0.5f);

        for(int x = p_sx; x < p_ex; x++ )
        {
            //color c = lerp_vc(c_sx, c_ex, (float32) (x - p_sx) / x_len);
            g_screen_put_pixel(x, y, COLOR(red));
        }
    }
#endif
}
#pragma clang diagnostic pop
#endif
void draw_triangle_flat_top(vx vx0, vx vx1, vx vx2)
{
#if 1
    const float32 delta_y = 1.f / (vx2.p[1] - vx0.p[1]);
    vx dvx0; dvx(dvx0, vx0, vx2, delta_y);
    vx dvx1; dvx(dvx1, vx1, vx2, delta_y);
    vx vx_start1 = vx1;
    draw_flat_triangle(vx0, vx2, dvx0, dvx1, vx_start1);
#endif
#if 0
    const int p_sy = (int)(ceilf(vx0.p[1] - 0.5f));
    const int p_ey = (int)(ceilf(vx2.p[1] - 0.5f));

    const float32 k0 = (vx2.p[0] - vx0.p[0]) / (vx2.p[1] - vx0.p[1]);
    const float32 k1 = (vx2.p[0] - vx1.p[0]) / (vx2.p[1] - vx1.p[1]);

    const float32 y_len = 1.f / (float32)(p_ey - p_sy);
    for (int y = p_sy; y < p_ey; y++)
    {
        const float32 lerp_y = (float32)(y - p_sy) * y_len;

        const float32 y_amount = ((float32)(y) + 0.5f - (float32)vx0.p[1]);
        const float32 x0 = k0 * y_amount + (float32)vx0.p[0];
        const float32 x1 = k1 * y_amount + (float32)vx1.p[0];

        const int p_sx = (int)ceilf(x0 - 0.5f);
        const int p_ex = (int)ceilf(x1 - 0.5f);
        const float32 x_len = 1.f / (float32)(p_ex - p_sx);

        const color c_sx = lerp_color(vx0.c, vx2.c, lerp_y);
        const color c_ex = lerp_color(vx1.c, vx2.c, lerp_y);

        for(int x = p_sx; x < p_ex; x++ )
        {
            const float32 lerp_x = (float32)(x - p_sx) * x_len;
            const color c = lerp_vc(c_sx, c_ex, lerp_x);
            g_screen_put_pixel(x, y, c);
        }
    }
#endif
}

void draw_triangle_flat_bottom(vx vx0, vx vx1, vx vx2)
{
#if 1
    const float32 delta_y = 1.f / (vx2.p[1] - vx0.p[1]);
    vx dvx0; dvx(dvx0, vx0, vx1, delta_y);
    vx dvx1; dvx(dvx1, vx0, vx2, delta_y);
    vx vx_start1 = vx0;
    draw_flat_triangle(vx0, vx2, dvx0, dvx1, vx_start1);
#endif
#if 0
    const int p_sy = (int)(ceilf(vx0.p[1] - 0.5f));
    const int p_ey = (int)(ceilf(vx2.p[1] - 0.5f));

    const float32 k0 = (vx1.p[0] - vx0.p[0]) / (vx1.p[1] - vx0.p[1]);
    const float32 k1 = (vx2.p[0] - vx0.p[0]) / (vx2.p[1] - vx0.p[1]);

    const float32 y_len = 1.f / (float32)(p_ey - p_sy);
    for (int y = p_sy; y < p_ey; y++)
    {
        const float32 lerp_y = (float32)(y - p_sy) * y_len;

        const float32 y_amount = ((float32)(y) + 0.5f - (float32)vx0.p[1]);
        const float32 x0 = k0 * y_amount + (float32)vx0.p[0];
        const float32 x1 = k1 * y_amount + (float32)vx0.p[0];

        const int p_sx = (int)ceilf(x0 - 0.5f);
        const int p_ex = (int)ceilf(x1 - 0.5f);
        const float32 x_len = 1.f / (float32)(p_ex - p_sx);

        const color c_sx = lerp_color(vx0.c, vx1.c, lerp_y);
        const color c_ex = lerp_color(vx0.c, vx2.c, lerp_y);

        for(int x = p_sx; x < p_ex; x++ )
        {
            const float32 lerp_x = (float32)(x - p_sx) * x_len;
            const color c = lerp_vc(c_sx, c_ex, lerp_x);
            g_screen_put_pixel(x, y, c);
        }
    }
#endif
}

// Get this algo from chilitomatonoodle, I think he get this anywhere else too
void draw_triangle(vx vx0, vx vx1, vx vx2) {
    if (vx0.p[1] > vx1.p[1]) {
        SWAP_VX(vx0, vx1);
    }
    if (vx1.p[1] > vx2.p[1]) {
        SWAP_VX(vx1, vx2);
    }
    if (vx0.p[1] > vx1.p[1]) {
        SWAP_VX(vx0, vx1);
    }
    if (unlikely(vx0.p[1] == vx1.p[1]))
    {
        if (vx0.p[0] > vx1.p[0]) {
            SWAP_VX(vx0, vx1);
        }
        draw_triangle_flat_top(vx0, vx1, vx2);
    } else if (unlikely(vx1.p[1] == vx2.p[1]))
    {
        if (vx1.p[0] > vx2.p[0]) {
            SWAP_VX(vx1, vx2);
        }
        draw_triangle_flat_bottom(vx0, vx1, vx2);
    } else
    {
        const float32 split = (vx1.p[1] - vx0.p[1]) / (vx2.p[1] - vx0.p[1]);
        vx v = lerp_vertex(vx0, vx2, split);
        if (v.p[0] < vx1.p[0])
        {
            //major-left
            draw_triangle_flat_bottom(vx0, v, vx1);
            draw_triangle_flat_top(v, vx1, vx2);
        } else
        {
            //major-right
            draw_triangle_flat_bottom(vx0, vx1, v);
            draw_triangle_flat_top(vx1, v, vx2);
        }
    }
}

void pipeline_draw(TriangleList* tl) {
    transform_vertices(tl->vert, tl->ind);
}

