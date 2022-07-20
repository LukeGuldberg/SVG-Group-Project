// Alyssa Ebeling

#pragma once

#include <vector>

#include "shape.h"

class Rectangle : public Shape {
   public:
    Rectangle(Point center_point, double x_length, double y_length);
    void draw(Canvas& canvas) override;

   protected:
    double x_length;
    double y_length;
    // calculated based on given centerpoint and x and y length
    std::vector<Point> points;
};