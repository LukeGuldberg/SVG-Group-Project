// Sam Sutton
#pragma once

#include "shape.h"
#include <vector>

class Reg_poly : public Shape { // Regular sided polygon
public:
    // Takes in center point, number of sides, and side length
    Reg_poly(Point center_point, int num_sides, int side_length);

    void draw(Canvas& canvas) override;

    double get_radius();
    double get_height();

private:
    // Calculates coordinates of each point
    void calc_points();

    int num_sides;
    int side_length;
    double radians;
    double radius;
    double height;
    std::vector<Point> points;
};