#include "voronoi/voronoi.hpp"

using namespace cv;

int main()
{
    Mat frame = Mat::zeros(800, 1200, CV_8UC3);

    // Points
    Points point1(100, 100);
    Points point2(100, 700);
    Points point3(1100, 100);
    Points point4(1100, 700);

    line(frame, Point(point1.x, point1.y), Point(point2.x, point2.y), Scalar(0, 255, 0), 8);
    line(frame, Point(point1.x, point1.y), Point(point3.x, point3.y), Scalar(0, 255, 0), 8);
    line(frame, Point(point2.x, point2.y), Point(point4.x, point4.y), Scalar(0, 255, 0), 8);
    line(frame, Point(point3.x, point3.y), Point(point4.x, point4.y), Scalar(0, 255, 0), 8);

    sites.push_back(point1);
    sites.push_back(point2);
    sites.push_back(point3);
    sites.push_back(point4);

    Voronoi(1200, 800, sites, frame);

    circle(frame, Point(point1.x, point1.y), 5, Scalar(0, 255, 0), 8);
    circle(frame, Point(point2.x, point2.y), 5, Scalar(0, 255, 0), 8);
    circle(frame, Point(point3.x, point3.y), 5, Scalar(0, 255, 0), 8);
    circle(frame, Point(point4.x, point4.y), 5, Scalar(0, 255, 0), 8);

    for (int i = 0; i < cells.size(); i++)
    {
        for (int j = 0; j < cells[i].edges.size(); j++)
        {
            // line(frame, Point(cells[i].edges[j].init.x, cells[i].edges[j].init.y), Point(cells[i].edges[j].final.x, cells[i].edges[j].final.y), Scalar(255, 0, 0), 5);
        }
    }
    imshow("Frame", frame);
    waitKey(0);
}