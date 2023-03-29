#include <math.h>
#include <iostream>

class p3vec
{
    float x, y, z;

public:
    p3vec(float x, float y, float z)
        : x(x), y(y), z(z) {}
    p3vec operator+(const p3vec &v) const
    {
        return p3vec(x + v.x, y + v.y, z + v.z);
    }
    p3vec operator-(const p3vec &v) const
    {
        return p3vec(x - v.x, y - v.y, z - v.z);
    }
    p3vec operator*(float f) const
    {
        return p3vec(x * f, y * f, z * f);
    }
    p3vec operator/(float f) const
    {
        return p3vec(x / f, y / f, z / f);
    }
    float dot(const p3vec &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    float length() const
    {
        return sqrt(dot(*this));
    }
    p3vec normalize() const
    {
        return *this / length();
    }
    p3vec cross(const p3vec &v) const
    {
        return p3vec(y * v.z - z * v.y,
                     z * v.x - x * v.z,
                     x * v.y - y * v.x);
    }
    float operator[](int i) const
    {
        return (&x)[i];
    }
    float &operator[](int i)
    {
        return (&x)[i];
    }
    void print() const
    {
        printf("(%f, %f, %f)\n", x, y, z);
    }
};
