#include "app.h"

void Corsac_App_Create(Corsac_App_Config config)
{
    if (SDL_Init(config.init_flags) < 0)
		corsac_panic("Couldn't initialize SDL: %s\n", SDL_GetError())

	if (IMG_Init(config.images_flags) < 0)
		corsac_panic("Couldn't initialize SDL: %s\n", SDL_GetError())

	Corsac_App.window = SDL_CreateWindow(config.title, config.window_pos_x, config.window_pos_x, config.window_width, config.window_height, config.window_flags);
	if (!Corsac_App.window)
		corsac_panic("Failed to open %d x %d window: %s\n", config.window_width, config.window_height, SDL_GetError())

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, config.scale_quality);

	Corsac_App.renderer = SDL_CreateRenderer(Corsac_App.window, -1, config.renderer_flags);
	if (!Corsac_App.renderer)
		corsac_panic("Failed to create renderer: %s\n", SDL_GetError())
}

void Corsac_App_Event()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

SDL_Texture* Corsac_Texture_Load(const char* filename)
{
	SDL_Texture* texture = IMG_LoadTexture(Corsac_App.renderer, filename);
	if (!texture) corsac_error("Failed to load image: %s\n", IMG_GetError())
	return texture;
}

void Corsac_Texture_Draw(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest = {.x = x, .y = y};
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(Corsac_App.renderer, texture, NULL, &dest);
}

void Corsac_Scene_Clear(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(Corsac_App.renderer, r, g, b, a);
	SDL_RenderClear(Corsac_App.renderer);
}

void Corsac_Scene_Present()
{
	SDL_RenderPresent(Corsac_App.renderer);
}

void Corsac_App_Exit(void)
{
	SDL_DestroyRenderer(Corsac_App.renderer);
	SDL_DestroyWindow(Corsac_App.window);
	SDL_Quit();
}