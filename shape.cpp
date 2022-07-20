// Alyssa Ebeling
#include "shape.h"

#include <stdexcept>

Shape::Shape(Point center_point) : center_point{center_point} {}

// these functions set the elements of the Properties struct
void Shape::set_edge_color(std::string color) { property.stroke = color; }

void Shape::set_fill_color(std::string color) { property.fill = color; }

void Shape::set_opacity(double opacity) { property.opacity = opacity; }