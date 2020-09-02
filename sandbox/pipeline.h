//
// Created by uberdever on 21.08.2020.
//

#ifndef ALPHABETA_PIPELINE_H
#define ALPHABETA_PIPELINE_H

#include "alphabeta.h"
#include "stuff/primitive_list.h"
#include "stuff/ndc.h"

void pipeline_bind_rotation(m3 rot);
void pipeline_bind_translation(v3 trans);

typedef struct texture {SDL_Surface* surf; vi2 size;} tex;
void pipeline_bind_texture(tex texture_);

void pipeline_draw(TriangleList* tl);

#endif //ALPHABETA_PIPELINE_H
