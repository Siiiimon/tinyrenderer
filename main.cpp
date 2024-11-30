#include "App/App.h"

void render(SDL_Renderer* renderer, SDL_Rect viewport) {
    SDL_SetRenderDrawColor(renderer, 0X01, 0X82, 0X3f, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

int main() {
    App app;

    app.Show(render);

    return 0;
}
