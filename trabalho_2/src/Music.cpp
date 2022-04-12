#include "Music.h"

Music::Music()
{
    music = nullptr;
}

Music::Music(string file)
{
    Open(file);
}

Music::~Music()
{
    Stop(0);
    Mix_FreeMusic(music);
}

void Music::Play(int times)
{
    if (!music)
    {
        throw("nullptr music");
    }
    if (Mix_PlayMusic(music, times))
    {
        cout << SDL_GetError() << endl;
    }
}

void Music::Stop(int msToStop)
{
    if (Mix_FadeOutMusic(msToStop))
    {
        cout << SDL_GetError() << endl;
    }
}

void Music::Open(string file)
{
    if (!(music = Mix_LoadMUS(file.c_str())))
    {
        cout << SDL_GetError() << endl;
    }
}

bool Music::IsOpen()
{
    return music != nullptr;
}
