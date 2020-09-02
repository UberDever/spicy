//
// Created by uberdever on 16.08.2020.
//

#ifndef ALPHABETA_NDC_H
#define ALPHABETA_NDC_H

#include "alphabeta.h"
/*
 *  NDC
 */

static void ndc_transform(const v3 vec, float32 scr_w, float32 scr_h, v3 res)
{
    const float32 scale_x = scr_w / 2; const float32 scale_y = scr_h / 2;
    const float32 z_inv = vec[2] ? 1.f / vec[2] : 1.f;
    res[0] = (vec[0] * z_inv + 1) * scale_x;
    res[1] = (-vec[1] * z_inv + 1) * scale_y;
}

#endif //ALPHABETA_NDC_H
