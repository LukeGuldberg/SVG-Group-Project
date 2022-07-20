// Alyssa Ebeling

#pragma once
#include <string>

#include "point.h"
#include "properties.h"
#include "svg.h"

class Shape {
   public:
    virtual void draw(Canvas&) = 0;

    // default edge and fill color is black
    void set_edge_color(std::string color);
    void set_fill_color(std::string color);
    // opacity is a decimal (e.g. .15 is 15% opaque)
    // default opacity is 1.0
    void set_opacity(double opacity);

   protected:
    // Canvas only has positive coordinates- (0,0) is in bottom left corner, so
    // don't use negative coordinates
    Shape(Point center_point);
    Point center_point;
    // properties structure holds edge color, fill colour, and opacity
    Properties property;
};