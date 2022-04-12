#include "Game.h"
#include "Sound.h"
#include <iostream>

Sound::Sound(GameObject &associated) : Component(associated), chunk(nullptr), channel(0) {}

Sound::Sound(GameObject &associated, string file) : Component(associated), chunk(nullptr), channel(0)
{
    Open(file);
}

Sound::~Sound()
{
    if (chunk != nullptr)
    {
        Stop();
    }
    Mix_FreeChunk(chunk);
}

void Sound::Play(int times)
{
    if ((channel = Mix_PlayChannel(-1, chunk, times - 1)) == -1)
    {
        cout << SDL_GetError() << endl;
        exit(1);
    }
}

void Sound::Stop()
{
    if (chunk != nullptr)
    {
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(string file)
{
    if (!(chunk = Mix_LoadWAV(file.c_str())))
    {
        cout<< SDL_GetError() << endl;
        exit(1);
    }
}

bool Sound::IsOpen()
{
    return chunk != nullptr;
}

void Sound::Update(float dt) {}

void Sound::Render() {}

bool Sound::Is(string type)
{
    return type == SOUND_TYPE;
}
