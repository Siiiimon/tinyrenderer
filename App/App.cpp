//
// Created by simon on 30/11/2024.
//

#include "App.h"

App::App() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    printf("Initialized SDL %d\n", SDL_GetVersion());

    SDL_CreateWindowAndRenderer("tinyrenderer", WIDTH, HEIGHT, 0, &window, &renderer);
    if (!window || !renderer) {
        printf("SDL could not create window and renderer: %s\n", SDL_GetError());
        return;
    }

    surface = SDL_GetWindowSurface(window);
}

App::~App() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void App::Show(const std::function<void(SDL_Renderer*, const SDL_Rect&)>& renderFunc) {
    bool isRunning = true;
    while (isRunning) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_EVENT_QUIT:
                    isRunning = false;
                break;
            }
        }

        SDL_Rect viewport;
        SDL_GetRenderViewport(renderer, &viewport);

        renderFunc(renderer, viewport);

        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
    }
}
