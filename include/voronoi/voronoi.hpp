/**
 * @file Voronoi.h
 * @author Danendra (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-01
 *
 * @copyright Copyright (c) 2023
 * @ref https://courses.cs.washington.edu/courses/cse326/00wi/projects/voronoi.html
 */
#include "opencv2/opencv.hpp"
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace cv;
using namespace std;

#define x first
#define y second

//---> Prototypes
//=================
class Points;
class Edge;
class Cell;
vector<Points> sites;

//------------------------------------

/**
 * Points as known as sites
 */
class Points
{
public:
    int x, y;
    Points(int x, int y) : x(x), y(y) {}
};

class Voronoi
{
public:
    Voronoi();
    ~Voronoi();
};

class Edge
{
public:
    Points init, final;

    Edge(const Points &init, const Points &final) : init(init), final(final) {}
};

class Cell
{
public:
    Points site;
    vector<Edge> edges;

    Cell(const Points &site) : site(site) {}

    void PushEdge(const Edge &edge)
    {
        edges.push_back(edge);
    }
};

vector<Cell>
    cells;

//---> Helper Function
Point Points2Point(Points inputed_point)
{
    return Point(inputed_point.x, inputed_point.y);
}

//---> Main Algorithm
void Voronoi(int width, int height, vector<Points> sites, Mat frame)
{
    Points p1(0, 0), p2(width, 0), p3(0, height), p4(width, height);
    Cell c1(p1), c2(p2), c3(p3), c4(p4);

    c1.PushEdge(Edge(p1, p2));
    c1.PushEdge(Edge(p1, p3));
    c2.PushEdge(Edge(p2, p4));
    c2.PushEdge(Edge(p2, p1));
    c3.PushEdge(Edge(p3, p1));
    c3.PushEdge(Edge(p3, p4));
    c4.PushEdge(Edge(p4, p3));
    c4.PushEdge(Edge(p4, p2));

    cells.push_back(c1);
    cells.push_back(c2);
    cells.push_back(c3);
    cells.push_back(c4);

    for (int site = 0; site < sites.size(); site++)
    {
        Cell c(sites[site]); // this ine is a buffer (doesnt affect the cells )

        for (int cell = 0; cell < cells.size(); cell++)
        {
            line(frame, Points2Point(cells[cell].site), Points2Point(sites[site]), Scalar(0, 0, 255), 1, 8, 0);
            int halfway_x = (cells[cell].site.x + sites[site].x) / 2;
            int halfway_y = (cells[cell].site.y + sites[site].y) / 2;

            Edge pb(Points(halfway_x, halfway_y), sites[site]);

            vector<Edge> X;

            for (int edge = 0; edge < cells[cell].edges.size(); edge++)
            {
                int dist_init_to_site = sqrt(pow(cells[cell].edges[edge].init.x - sites[site].x, 2) + pow(cells[cell].edges[edge].init.y - sites[site].y, 2));
                int dist_final_to_site = sqrt(pow(cells[cell].edges[edge].final.x - sites[site].x, 2) + pow(cells[cell].edges[edge].final.y - sites[site].y, 2));

                int dist_init_to_cs = sqrt(pow(cells[cell].edges[edge].init.x - cells[cell].site.x, 2) + pow(cells[cell].edges[edge].init.y - cells[cell].site.y, 2));
                int dist_final_to_cs = sqrt(pow(cells[cell].edges[edge].final.x - cells[cell].site.x, 2) + pow(cells[cell].edges[edge].final.y - cells[cell].site.y, 2));

                // if the edge is closer to the site than the cell site, delete the edge
                if (dist_init_to_site < dist_init_to_cs && dist_final_to_site < dist_final_to_cs)
                {
                    cells[cell].edges.erase(cells[cell].edges.begin() + edge);
                    edge--;
                }

                if (dist_init_to_site < dist_final_to_site)
                {
                    cells[cell].edges[edge].final = pb.final;
                }
                else
                {
                    cells[cell].edges[edge].init = pb.init;
                }

                X.push_back(cells[cell].edges[edge]);
            }
            if (X.size() == 2)
            {
                cells[cell].edges = X;
            }
        }
    }
}