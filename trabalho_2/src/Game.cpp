#define SLD_FLAGS (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)
#define IMG_FLAGS (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)
#define MIX_FLAGS MIX_INIT_OGG

#define CHUNKSIZE 1024
#define NUMCHANS 32

#define TITLE "Lieverton 17/0039251"
#define WIDTH 1024
#define HEIGHT 600

#define DELAY 33 // 33ms ~ 30FPS

#include "Game.h"
#include <iostream>

Game::Game(string title, int width, int heigth)
{
    if (instance != nullptr)
    {
        throw("Game already intancied");
    }

    instance = this;

    if (SDL_Init(SLD_FLAGS))
    {
        cout << SDL_GetError() << endl;
    }

    if (IMG_Init(IMG_FLAGS) != IMG_FLAGS)
    {
        cout << SDL_GetError() << endl;
    }

    if (Mix_Init(MIX_FLAGS) != MIX_FLAGS)
    {
        cout << SDL_GetError() << endl;
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, CHUNKSIZE))
    {
        cout << SDL_GetError() << endl;
    }

    if (Mix_AllocateChannels(NUMCHANS) != NUMCHANS)
    {
        cout << SDL_GetError() << endl;
    }

    if (!(window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, 0)))
    {
        cout << SDL_GetError() << endl;
    }

    // Use the value -1: This will make SDL choose the best renderer for the environment and the flags set.
    if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)))
    {
        cout << SDL_GetError() << endl;
    }

    state = new State();
}

Game::~Game()
{
    delete (state);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

Game *Game::instance = nullptr;

Game &Game::GetInstance()
{
    if (instance != nullptr)
    {
        return *instance;
    }

    return *new Game(TITLE, WIDTH, HEIGHT);
}

State &Game::GetState()
{
    return *state;
}

SDL_Renderer *Game::GetRenderer()
{
    return renderer;
}

void Game::Run()
{
    while (!state->QuitRequested())
    {
        state->Update(0);
        state->Render();

        SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);
    }
}
