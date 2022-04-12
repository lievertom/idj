#include "Face.h"
#include "Sound.h"
#include "Sprite.h"

Face::Face(GameObject &associated) : Component(associated), hitpoints(30) {}

void Face::Damage(int damage)
{
    hitpoints -= damage;
    if (hitpoints <= 0)
    {
        Sprite *sprite = (Sprite *)associated.GetComponent(SPRITE_TYPE);
        if (sprite != nullptr)
        {
            Sound *sound = (Sound *)associated.GetComponent(SOUND_TYPE);
            if (sound != nullptr)
            {
                sound->Play();
                associated.RemoveComponent(sprite);
            }
            else
            {
                associated.RequestDelete();
            }
        }
    }
}

void Face::Update(float dt) {}

void Face::Render() {}

bool Face::Is(string type)
{
    return type == FACE_TYPE;
}