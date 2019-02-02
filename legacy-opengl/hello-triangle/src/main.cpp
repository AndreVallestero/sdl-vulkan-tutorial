#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

int main(void) {
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("hello-triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 360, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(window);

    bool running = true;
    while(running) {
        SDL_Event windowEvent;
        while(SDL_PollEvent(&windowEvent))
            if(windowEvent.type == SDL_QUIT) {
                running = false;
                break;
            }

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}