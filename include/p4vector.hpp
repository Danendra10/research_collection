#include <math.h>
#include <iostream>
#include "p3vector.hpp"
#include <vector>

using namespace std;

class p4vec
{
    float x, y, z, w;
    vector<p3vec> points;

public:
    p4vec(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {}
    p4vec operator+(const p4vec &v) const
    {
        return p4vec(x + v.x, y + v.y, z + v.z, w + v.w);
    }
    p4vec operator-(const p4vec &v) const
    {
        return p4vec(x - v.x, y - v.y, z - v.z, w - v.w);
    }
    p4vec operator*(float f) const
    {
        return p4vec(x * f, y * f, z * f, w * f);
    }
    p4vec operator/(float f) const
    {
        return p4vec(x / f, y / f, z / f, w / f);
    }
    float dot(const p4vec &v) const
    {
        return x * v.x + y * v.y + z * v.z + w * v.w;
    }
    float length() const
    {
        return sqrt(dot(*this));
    }
    p4vec normalize() const
    {
        return *this / length();
    }
    p4vec cross(const p4vec &v) const
    {
        return p4vec(y * v.z - z * v.y,
                     z * v.x - x * v.z,
                     x * v.y - y * v.x,
                     0);
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
        printf("Four Dimensional Vector:\n");
        printf("(%f, %f, %f, %f)\n", x, y, z, w);
        printf("========================\n");
        printf("Three Dimensional Vector:\n");
        printf("(%f, %f, %f)\n", x, y, z);
    }

    

private:
    vector<p3vec> getpoints()
    {
        return points;
    }

    void projectfourdtothreed()
    {
        points = {
            p3vec(x, y, z),
            p3vec(x, y, w),
            p3vec(x, z, w),
            p3vec(y, z, w),
        };
    }
};