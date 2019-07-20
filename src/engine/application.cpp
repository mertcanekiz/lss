#include "application.h"

namespace melkor
{
    application::application(unsigned int width, unsigned int height, const char* title, bool fullscreen)
        : width(width),
        height(height),
        title(title),
        fullscreen(fullscreen)
    {
        window = nullptr;
    }

    application::~application()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void application::run()
    {
        if (init() == false) {
            exit(EXIT_FAILURE);
        }

        running = true;
        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }
            SDL_SetRenderDrawColor(renderer, 0x00, 0x88, 0x88, 0xff);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    bool application::init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
            return false;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

        if (window == nullptr) {
            std::cerr << "Could not create SDL window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (renderer == nullptr) {
            std::cerr << "Could not create SDL Renderer: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return false;
        }

        return true;
    }
}
