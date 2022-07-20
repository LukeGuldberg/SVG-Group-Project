// Alyssa Ebeling

#include "line.h"

#include <iostream>
#include <stdexcept>

// Canvas only has positive coordinates- (0,0) is in bottom left corner
Line::Line(Point center_point, Point end_point)
    : Shape{center_point}, end_point{end_point} {
    if (end_point.x < 0 || end_point.y < 0) {
        throw std::runtime_error("Error: point 2 cannot be negative!");
    }
}
void Line::draw(Canvas& canvas) {
    canvas.line(center_point, end_point, property);
}