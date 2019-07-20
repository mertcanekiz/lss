#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace melkor
{
    class application
    {
        public:
            application(unsigned int width, unsigned int height, const char* title, bool fullscreen);
            virtual ~application();

            void run();
            bool init();

        private:
            unsigned int width;
            unsigned int height;
            const char* title;
            bool fullscreen;

            SDL_Window* window;
            SDL_Renderer* renderer;
            SDL_Event event;

            bool running;
    };
}