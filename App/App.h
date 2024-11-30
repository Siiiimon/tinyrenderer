//
// Created by simon on 30/11/2024.
//

#ifndef APP_H
#define APP_H

#include <iostream>
#include <SDL3/SDL.h>


class App {
public:
    App();
    ~App();

    void Show();
private:
    static const int WIDTH = 800;
    static const int HEIGHT = 600;

    SDL_Window* window;
    SDL_Renderer* renderer;
};



#endif //APP_H
