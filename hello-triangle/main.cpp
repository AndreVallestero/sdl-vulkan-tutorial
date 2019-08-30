#include <SDL/SDL.h>
#include <SDL/SDL_vulkan.h>

int main(int argc, char * argv[]) {
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("hello-triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 360, SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
    SDL_GL_CreateContext(window);

    bool running = true;
    while(running) {
        SDL_Event windowEvent;
        while(SDL_PollEvent(&windowEvent))
            if(windowEvent.type == SDL_QUIT) {
                running = false;
                break;
            }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}