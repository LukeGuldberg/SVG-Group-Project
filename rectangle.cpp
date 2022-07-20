// Alyssa Ebeling

#include "rectangle.h"

#include <stdexcept>
#include <vector>

#include <iostream>
Rectangle::Rectangle(Point center_point, double x_length, double y_length)
    : Shape{center_point}, x_length{x_length}, y_length{y_length} {
    if (x_length < 1 || y_length < 1) {
        throw std::runtime_error(
            "Error: x_length and y_length cannot be less than 1!");
    }
}

void Rectangle::draw(Canvas& canvas) {
    // points calculated clockwise starting from bottom left corner
    Point point1{center_point.x - x_length / 2, center_point.y - y_length / 2};
    Point point2{center_point.x - x_length / 2, center_point.y + y_length / 2};
    Point point3{center_point.x + x_length / 2, center_point.y + y_length / 2};
    Point point4{center_point.x + x_length / 2, center_point.y - y_length / 2};

    std::vector<Point> points{point1, point2, point3, point4};
    canvas.polyline(points, property);
}