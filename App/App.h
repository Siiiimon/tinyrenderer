//
// Created by simon on 30/11/2024.
//

#ifndef APP_H
#define APP_H

#include <iostream>
#include <functional>
#include <SDL3/SDL.h>


class App {
public:
    App();
    ~App();

    void Show(const std::function<void(SDL_Renderer*, const SDL_Rect&)>& renderFunc);
private:
    static const int WIDTH = 800;
    static const int HEIGHT = 600;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
};



#endif //APP_H
