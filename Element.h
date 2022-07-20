//Luke
#pragma once
#include "properties.h"
#include "point.h"
#include <string>
#include <vector>

class Element{
public:
// overflow constructors, one for each specific draw function.
    Element(std::string type, std::vector<Point> pts, Properties prop); // polyline constructor
    Element(std::string type, Point pt1, Point pt2, Properties prop); // line constructor
    Element(std::string type, Point center, double radiusx, double radiusy, Properties prop); // ellipse constructor
    
    std::string type;
    std::vector<Point> pts;
    Properties prop;
    Point pt1;
    Point pt2;
    Point center;
    double radiusx;
    double radiusy;
};
