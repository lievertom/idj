#ifndef VEC2_H
#define VEC2_H

class Vec2
{
private:

public:
    float x, y;

    Vec2();

    Vec2(float x, float y);

    Vec2 Sum(Vec2 v);

    Vec2 Sub(Vec2 v);

    Vec2 Mul(float escalar);

    float Mag();

    Vec2 Norm();

    float Dist(Vec2 v);

    float InclX();

    float Incl(Vec2 v);

    Vec2 GetRotated(float ang);

    Vec2 & operator+(const Vec2& v);
    
    Vec2 & operator-(const Vec2& v);
    
    Vec2 & operator=(const Vec2& v);
    
    bool operator==(const Vec2& v);
};

#endif /* VEC_H */
