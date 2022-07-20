#include <iostream>

#include "ellipse.h"
#include "hex_tiles.h"
#include "rectangle.h"
#include "reg_poly.h"
#include "shape.h"

int main() {
    try {
        Point viewbox = {1500, 800};
        Svg svg(viewbox);

        Point background_center = {viewbox.x / 2, viewbox.y / 2};
        Rectangle background = {background_center, viewbox.x, viewbox.y};
        background.set_fill_color("lime");
        background.draw(svg);

        Hex_tiles hex_tiles = {50, 5, viewbox};
        hex_tiles.set_hex_color("black");
        hex_tiles.set_hex_opacity(0);
        hex_tiles.draw(svg);

        svg.save("hex_tiles.svg");

    } catch (std::runtime_error& error) {
        std::cout << error.what() << "\n";
    }
}
