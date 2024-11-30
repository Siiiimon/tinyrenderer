#include "App/App.h"

void line(int x0, int y0, int x1, int y1, SDL_Renderer* renderer, SDL_Color color) {
    for (float t=0.; t<1.; t+=.01) {
        int x = x0 + (x1-x0)*t;
        int y = y0 + (y1-y0)*t;
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderPoint(renderer, x, y);
    }
}

void render(SDL_Renderer* renderer, SDL_Rect viewport) {
    line(100, 100, 150, 100, renderer, SDL_Color{0XFF, 0XFF, 0XFF});
}

int main() {
    App app;

    app.Show(render);

    return 0;
}
