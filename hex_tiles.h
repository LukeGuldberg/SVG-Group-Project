// Sam Sutton
#pragma once

#include "shape.h"
#include "reg_poly.h"
#include <vector>

// Pattern of tiled hexagons
class Hex_tiles : public Shape {
public:
    // Side length is size of each side of the hexagon, and gap size is the size of the gap between each hexagon    
    Hex_tiles(int side_length, double gap_size, Point viewbox_size);

    void set_hex_color(std::string color);
    void set_hex_opacity(double opacity);

    void draw(Canvas& canvas) override;

private:
    // Creates a vector of Reg_polys with 6 sides using center points from calc_center_points()
    std::vector<Reg_poly> make_hexagons();
    // Calculates center points of tiled hexagons and uses calc_y_points for help
    void calc_center_points();
    // Calculates the center points for hexagons above and below a given point
    void calc_y_points(Point center);

    int side_length;
    double gap_size;
    Point viewbox_size;
    Reg_poly base;
    double x_distance;
    double y_distance;
    int width;
    int height;
    std::vector<Point> center_points;
    std::vector<Reg_poly> hexagons;
};