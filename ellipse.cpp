// Sam Sutton
#include "ellipse.h"
#include <vector>
#include <stdexcept>

Ellipse::Ellipse(Point center_point, double x_radius, double y_radius)
    :Shape{center_point}, x_radius{x_radius}, y_radius{y_radius} {
        if (x_radius < 1 || y_radius < 1) {
            throw std::runtime_error("Error: Radius cannot be less than 1!");
        }
    }

void Ellipse::draw(Canvas& canvas) {
    canvas.ellipse(center_point, x_radius, y_radius, property);
}


