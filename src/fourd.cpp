#include "p4vector.hpp"
#include <vector>
#include "opencv2/opencv.hpp"

using namespace std;

vector<p4vec> points;

void projectfourdtothreed()
{
    points = {
        p3vec(x, y, z),
        p3vec(x, y, w),
        p3vec(x, z, w),
        p3vec(y, z, w),
    };
}

void setup()
{
    points = {
        p4vec(0, 0, 0, 0),
        p4vec(1, 0, 0, 0),
        p4vec(0, 1, 0, 0),
        p4vec(0, 0, 1, 0),
        p4vec(0, 0, 0, 1),
        p4vec(1, 1, 1, 1),
    };
}

int main()
{
    setup();
    // for (auto p : points)
    // {
    //     p.print();
    // }

    points.projectfourdtothreed();
    for (auto p : points)
    {
        p.print();
    }
}