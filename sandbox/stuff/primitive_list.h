//
// Created by uberdever on 24.08.2020.
//

#ifndef SPICY_RENDERER_PRIMITIVE_LIST_H
#define SPICY_RENDERER_PRIMITIVE_LIST_H

#include "alphabeta.h"

typedef struct vcolor {
    float32 a;
    float32 r;
    float32 g;
    float32 b;
} vc;

typedef struct vertex {
    v3 p; v2 t; vc c; v3 n;
} vx;

static vc lerp_vc(vc c0, vc c1, float32 amount)
{
    vc c;
    c.a = pi_lerp(c0.a, c1.a, amount);
    c.r = pi_lerp(c0.r, c1.r, amount);
    c.g = pi_lerp(c0.g, c1.g, amount);
    c.b = pi_lerp(c0.b, c1.b, amount);
    return c;
}

#define dvx(v, vx_start, vx_end, delta) \
    v.p[0] = (vx_end.p[0] - vx_start.p[0]) * delta;\
    v.p[1] = (vx_end.p[1] - vx_start.p[1]) * delta;\
    v.c.a = (float32)(vx_end.c.a - vx_start.c.a) * delta;\
    v.c.r = (float32)(vx_end.c.r - vx_start.c.r) * delta;\
    v.c.g = (float32)(vx_end.c.g - vx_start.c.g) * delta;\
    v.c.b = (float32)(vx_end.c.b - vx_start.c.b) * delta;\
    v.t[0] = (vx_end.t[0] - vx_start.t[0]);\
    v.t[1] = (vx_end.t[1] - vx_start.t[1]);


static vx lerp_vertex(vx vx0, vx vx1, float32 amount)
{
    vx v;
    v.p[0] = pi_lerp(vx0.p[0], vx1.p[0], amount);
    v.p[1] = pi_lerp(vx0.p[1], vx1.p[1], amount);
    v.p[2] = 1;
    v.t[0] = pi_lerp(vx0.t[0], vx1.t[0], amount);
    v.t[1] = pi_lerp(vx0.t[1], vx1.t[1], amount);
    v.c = lerp_vc(vx0.c, vx1.c, amount);
    return v;
}

vx tmp_swap_vx_var_;
#define SWAP_VX(vx0, vx1) (tmp_swap_vx_var_ = vx0, vx0 = vx1, vx1 = tmp_swap_vx_var_)

typedef struct LineList {
    v3* vert;
    uint* ind;
} LineList;

static void linelist_new(struct LineList* ll, uint size)
{
    vec_new(ll->vert, size);
    vec_new(ll->ind, size * 3);
}

static void linelist_free(struct LineList* ll)
{
    vec_free(ll->vert);
    vec_free(ll->ind);
}

typedef struct TriangleList {
    vx* vert;
    uint* ind;
} TriangleList;

static void trianglelist_new(struct TriangleList* tl, uint vx_count, uint ind_count)
{
    vec_new(tl->vert, vx_count);
    vec_get_size(tl->vert) = vx_count;
    vec_new(tl->ind, ind_count);
    vec_get_size(tl->ind) = ind_count;
}

static void trianglelist_free(struct TriangleList* tl)
{
    vec_free(tl->vert);
    vec_free(tl->ind);
}
/*
 *  Simple 3d shapes
 */

static void shape_cube_lines(struct LineList* ll, vec_float_t side_len)
{
    const vec_float_t s = side_len / 2.;
    pi_v3(ll->vert[0], -s, -s, +s); ll->ind[0] = 0; ll->ind[8] = 0;  ll->ind[16] = 4;
    pi_v3(ll->vert[1], +s, -s, +s); ll->ind[1] = 1; ll->ind[9] = 4;  ll->ind[17] = 5;
    pi_v3(ll->vert[2], -s, +s, +s); ll->ind[2] = 1; ll->ind[10] = 1; ll->ind[18] = 5;
    pi_v3(ll->vert[3], +s, +s, +s); ll->ind[3] = 3; ll->ind[11] = 5; ll->ind[19] = 7;
    pi_v3(ll->vert[4], -s, -s, -s); ll->ind[4] = 3; ll->ind[12] = 3; ll->ind[20] = 7;
    pi_v3(ll->vert[5], +s, -s, -s); ll->ind[5] = 2; ll->ind[13] = 7; ll->ind[21] = 6;
    pi_v3(ll->vert[6], -s, +s, -s); ll->ind[6] = 2; ll->ind[14] = 2; ll->ind[22] = 6;
    pi_v3(ll->vert[7], +s, +s, -s); ll->ind[7] = 0; ll->ind[15] = 6; ll->ind[23] = 4;
}

static void shape_cube_triangles(struct TriangleList* tl, vec_float_t side_len)
{
    const vec_float_t s = side_len / 2.;
    pi_v3(tl->vert[0].p, -s, -s, -s);
    pi_v3(tl->vert[1].p, +s, -s, -s);
    pi_v3(tl->vert[2].p, -s, +s, -s);
    pi_v3(tl->vert[3].p, +s, +s, -s);
    pi_v3(tl->vert[4].p, -s, -s, +s);
    pi_v3(tl->vert[5].p, +s, -s, +s);
    pi_v3(tl->vert[6].p, -s, +s, +s);
    pi_v3(tl->vert[7].p, +s, +s, +s);
    uint tmp[] = {0,2,1, 2,3,1,
                  1,3,5, 3,7,5,
                  2,6,3, 3,6,7,
                  4,5,7, 4,7,6,
                  0,4,2, 2,4,6,
                  0,1,4, 1,5,4};
    memcpy(tl->ind, tmp, sizeof(tmp));
}

static void shape_cube_triangles_textured(struct TriangleList* tl, vec_float_t side_len)
{
    const vec_float_t s = side_len / 2.;
    pi_v3(tl->vert[0].p, -s, -s, -s); pi_v2(tl->vert[0].t, 1, 0);
    pi_v3(tl->vert[1].p, +s, -s, -s); pi_v2(tl->vert[1].t, 0, 0);
    pi_v3(tl->vert[2].p, -s, +s, -s); pi_v2(tl->vert[2].t, 1, 1);
    pi_v3(tl->vert[3].p, +s, +s, -s); pi_v2(tl->vert[3].t, 0, 1);
    pi_v3(tl->vert[4].p, -s, -s, +s); pi_v2(tl->vert[4].t, 1, 3);
    pi_v3(tl->vert[5].p, +s, -s, +s); pi_v2(tl->vert[5].t, 0, 3);
    pi_v3(tl->vert[6].p, -s, +s, +s); pi_v2(tl->vert[6].t, 1, 2);
    pi_v3(tl->vert[7].p, +s, +s, +s); pi_v2(tl->vert[7].t, 0, 2);
    pi_v3(tl->vert[8].p, -s, -s, -s); pi_v2(tl->vert[8].t, 1, 4);
    pi_v3(tl->vert[9].p, +s, -s, -s); pi_v2(tl->vert[9].t, 0, 4);
    pi_v3(tl->vert[10].p, -s, -s, -s); pi_v2(tl->vert[10].t, 2, 1);
    pi_v3(tl->vert[11].p, -s, -s, +s); pi_v2(tl->vert[11].t, 2, 2);
    pi_v3(tl->vert[12].p, +s, -s, -s); pi_v2(tl->vert[12].t, +1, 1);
    pi_v3(tl->vert[13].p, +s, -s, +s); pi_v2(tl->vert[13].t, +1, 2);
    uint tmp[] = {0,2,1,   2,3,1,
                  4,8,5,   5,8,9,
                  2,6,3,   3,6,7,
                  4,5,7,   4,7,6,
                  2,10,11, 2,11,6,
                  12,3,7,  12,7,13};
    memcpy(tl->ind, tmp, sizeof(tmp));
}

#endif //SPICY_RENDERER_PRIMITIVE_LIST_H
