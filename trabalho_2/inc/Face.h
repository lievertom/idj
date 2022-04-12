#ifndef FACE_H
#define FACE_H

#define FACE_TYPE "Face"

#include "Component.h"

class Face : public Component
{
private:
    int hitpoints;

public:
    Face(GameObject &associated);

    void Damage(int damage);

    void Update(float dt);

    void Render();

    bool Is(string type);
};

#endif /* FACE_H */