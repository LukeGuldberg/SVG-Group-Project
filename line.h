// Alyssa Ebeling

#pragma once

#include "shape.h"

class Line : public Shape {
   public:
   // center_point functions as the starting point
    Line(Point center_point, Point end_point);
    // set_fill_color function does nothing for a line. Use set_edge_color
    void draw(Canvas& canvas) override;

   protected:
    Point end_point;
};