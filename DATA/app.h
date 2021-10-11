// Copyright (c) 2021 Corsac Team
// License: MIT License
// MIT License web page: https://opensource.org/licenses/MIT
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "panic.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _Corsac_App
{
	SDL_Renderer* renderer;
	SDL_Window* window;
} static Corsac_App;

typedef struct
{
	const char* title;

	Uint32 init_flags;
	Uint32 window_flags;
	Uint32 renderer_flags;
	Uint32 images_flags;

	int window_pos_x;
	int window_pos_y;

	int window_width;
	int window_height;

	const char* scale_quality;

} Corsac_App_Config;

void Corsac_App_Create(Corsac_App_Config config);

void Corsac_App_Exit();

void Corsac_App_Event();

SDL_Texture* Corsac_Texture_Load(const char* filename);

void Corsac_Texture_Draw(SDL_Texture* texture, int x, int y);

void Corsac_Scene_Clear(int r, int g, int b, int a);

void Corsac_Scene_Present();

#ifdef __cplusplus
}
#endif