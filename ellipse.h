// Sam Sutton
#pragma once

#include "shape.h"

class Ellipse : public Shape {
public:
    Ellipse(Point center_point, double x_radius, double y_radius);

    void draw(Canvas& canvas) override;

private:
    double x_radius;
    double y_radius;
};