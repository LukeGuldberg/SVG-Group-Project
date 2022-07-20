// Sam Sutton
#include "hex_tiles.h"

#include <stdexcept>

// Hex_tiles = Pattern of tiled hexagons
// Side length is size of each side of the hexagon, and gap size is the size of the gap between each hexagon
Hex_tiles::Hex_tiles(int side_length, double gap_size, Point viewbox_size)
    // Center point is in center of viewbox
    : Shape{Point{viewbox_size.x / 2, viewbox_size.y / 2}},
      // Side length of each hexagon
      side_length{side_length},
      // Size of gap between each hexagon
      gap_size{gap_size},
      viewbox_size{viewbox_size},
      // Hexagon in the center -  all other hexagons are calculated based on it
      base{Reg_poly{center_point, 6, side_length}},
      // Distance between horizontal hexagons with the same Y coordinate (every other hexagon)
      x_distance{(base.get_radius() * 2) + (gap_size * 2) + side_length},
      // Distance between vertical hexagons
      y_distance{(base.get_height() * 2) + gap_size},
      // How many hexagons should be generated horizontally from the center point,
      // it divides by two since horizontal hexagon calculations are split into odd and even
      // and it adds two to make sure it goes over the edge
      width{static_cast<int>(((center_point.x / (base.get_radius() * 2)) / 2) + 2)},
      // How many hexagons should be generated vertically from the center point,
      // and it adds two to make sure it goes over the edge
      height{static_cast<int>((center_point.y / y_distance) + 2)},
      hexagons{make_hexagons()}{
    if (side_length < 1) {
        throw std::runtime_error("Error: Side length cannot be less than 1!");
    }
    if (gap_size < 0) {
        throw std::runtime_error("Error: gap length cannot be less than 0!");
    }
}

// Creates a vector of Reg_polys with 6 sides using center points from calc_center_points
std::vector<Reg_poly> Hex_tiles::make_hexagons() {
    calc_center_points();

    std::vector<Reg_poly> hexes;
    for (Point center : center_points) {
        Reg_poly hex = {center, 6, side_length};
        hexes.push_back(hex);
    }
    return hexes;
}

// Calculates center points of tiled hexagons
void Hex_tiles::calc_center_points() {
    // Adds center of base hexagon to vector of center points
    center_points.push_back(center_point);
    // Adds center points of all hexagons above & below base hexagon to vector
    calc_y_points(center_point);

    // Calculates center points of odd hexagons to the left
    int left_odd;
    for (left_odd = 1; left_odd <= width; ++left_odd) {
        Point a = {center_point.x - (left_odd * x_distance), center_point.y};
        center_points.push_back(a);
        // Calculates points for hexagons above & below each left odd hexagon
        calc_y_points(a);
    }

    // Calculates center points of odd hexagons to the right
    int right_odd;
    for (right_odd = 1; right_odd <= width; ++right_odd) {
        Point b = {center_point.x + (right_odd * x_distance), center_point.y};
        center_points.push_back(b);
        // Calculates points for hexagons above & below each right odd hexagon
        calc_y_points(b);
    }


    // Calculates center point of the hexagon just diagonally above/to the left of the center hexagon
    // Even hexagons are calculated based on this point
    Point even_center = {center_point.x - (x_distance / 2),
                              center_point.y + (y_distance / 2)};
    center_points.push_back(even_center);
    // Calculates points for hexagons above & below the even center hexagon
    calc_y_points(even_center);
    
    // Calculates center points of even hexagons to the left
    int left_even;
    for (left_even = 1; left_even <= width; ++left_even) {
        Point c = {even_center.x - (left_even * x_distance),
                   even_center.y};
        center_points.push_back(c);
        // Calculates points for hexagons above & below each left even hexagon
        calc_y_points(c);
    }

    // Calculates center points of even hexagons to the right
    int right_even;
    // Right even goes until width +1 because even_base is skewed to the left
    for (right_even = 1; right_even <= width + 1; ++right_even) {
        Point d = {even_center.x + (right_even * x_distance),
                   even_center.y};
        center_points.push_back(d);
        // Calculates points for hexagons above & below each right even hexagon
        calc_y_points(d);
    }
}

// Calculates center points of hexagons above & below a given center point
void Hex_tiles::calc_y_points(Point center) {
    // Calculates all center points above a given point
    int up;
    for (up = 1; up <= height; ++up) {
        Point a = {center.x, center.y + (up * y_distance)};
        center_points.push_back(a);
    }

    // Calculates all center points below a given point
    int down;
    for (down = 1; down <= height; ++down) {
        Point b = {center.x, center.y - (down * y_distance)};
        center_points.push_back(b);
    }
}

void Hex_tiles::set_hex_color(std::string color) {
    for (Reg_poly& hex : hexagons) {
        hex.set_fill_color(color);
        // Sets edge color same as fill color because there's already a gap
        // bordering the hexagons
        hex.set_edge_color(color);
    }
}

void Hex_tiles::set_hex_opacity(double opacity) {
    for (Reg_poly& hex : hexagons) {
        hex.set_opacity(opacity);
    }
}

void Hex_tiles::draw(Canvas& canvas) {
    for (Reg_poly hex : hexagons) {
        hex.draw(canvas);
    }
}