cmake_minimum_required(VERSION 3.16)
project(spicy_renderer C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(
        src
        include

        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} sandbox/main.c include/alpha.h include/delta.h src/alpha.c src/alphabeta.c include/alphabeta.h include/delta/vec.h include/gamma.h src/gamma.c include/pi.h include/omega.h include/beta.h include/delta/hash_table.h include/delta/queue.h include/delta/stack.h include/delta/deck.h sandbox/scene.h sandbox/scenes/cube.c src/gamma/alphabet.c sandbox/scenes/star.c sandbox/stuff/ndc.h sandbox/scenes/triangle.c sandbox/pipeline.h sandbox/pipeline.c sandbox/stuff/primitive_list.h sandbox/scenes/quad.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        -lm)