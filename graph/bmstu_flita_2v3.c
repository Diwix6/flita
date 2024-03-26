#include <stdio.h>
#include <SDL2/SDL.h>

// Граф
int graph[5][5] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Graph Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);

    // Рисуем узлы и рёбра
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < 5; i++) {
        SDL_RenderDrawPoint(renderer, 50 + 50 * i, 50); // Расположение узла
        for (int j = i; j < 5; j++) {
            if (graph[i][j] == 1) {
                SDL_RenderDrawLine(renderer, 50 + 50 * i, 50, 50 + 50 * j, 50); // Рисуем ребро
            }
        }
    }

    // Отображаем результат и ждём закрытия окна
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    // Очищаем ресурсы
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
