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

    window = SDL_CreateWindow("tinyrenderer", 800, 600, 0);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
}

App::~App() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void App::Show() {
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

        SDL_SetRenderDrawColor(renderer, 0X01, 0X82, 0X3f, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}
