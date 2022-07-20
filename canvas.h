// Jaxon
#pragma once
#include <vector>

#include "point.h"
#include "properties.h"
class Canvas {
   public:
    // These are our draw functions that will be overridden in svg.h
    virtual void polyline(std::vector<Point>, Properties prop) = 0;
    virtual void line(Point pt1, Point pt2, Properties prop) = 0;
    virtual void ellipse(Point center, double radiusx, double radiusy,
                         Properties prop) = 0;
};
