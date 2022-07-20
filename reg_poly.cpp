// Sam Sutton
#include "reg_poly.h"

#include <cmath>
#include <stdexcept>

// Reg_poly = Regular sided polygon
// Takes in center point, number of sides, and side length
Reg_poly::Reg_poly(Point center_point, int num_sides, int side_length)
    :Shape{center_point}, num_sides{num_sides}, side_length{side_length},
    radians{(2 * M_PI) / (num_sides * 2)}, radius{(side_length / 2) / sin(radians)},
    // Distance from the center point to the middle of one of the sides
    height{radius * cos(radians)} {
    if (num_sides < 3 || num_sides > 180) {
        throw std::runtime_error("Error: Number of sides must be between 3 and 180!");
    }
    if (side_length < 1) {
        throw std::runtime_error("Error: Side length cannot be less than 1!");
    }
}

// Calculates the points of the regular polygon and puts them in a vector
void Reg_poly::calc_points() {
   
    int i;
    // Calculates points for all regular polygons except hexagons
    if (num_sides != 6) {
        for (i = 0; i < num_sides; ++i) {
            Point p = {center_point.x - radius * sin(i * radians * 2),
                       center_point.y - radius * cos(i * radians * 2)};
            points.push_back(p);
        }
    }
    else { // Hexagons have the forumla with cos and sin flipped to rotate them 90 degrees
    // Hexagons are rotated so they are flat on the bottom and look nice for tiling
        for (i = 0; i < num_sides; ++i) {
                Point p = {center_point.x - radius * cos(i * radians * 2),
                           center_point.y - radius * sin(i * radians * 2)};
            points.push_back(p);
        }
    }
}

void Reg_poly::draw(Canvas& canvas) {
    calc_points();
    canvas.polyline(points, property);
}

double Reg_poly::get_radius() {
    return radius;
}

double Reg_poly::get_height() {
    return height;
}