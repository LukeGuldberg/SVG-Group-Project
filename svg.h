// Matt
// Luke
// Jaxon
// We all added to this file as we found new functions we would need.
#pragma once
#include <string>
#include <vector>

#include "Element.h"
#include "canvas.h"
#include "point.h"
#include "properties.h"

class Svg : public Canvas {
   public:
    // constructor that sets the canvas size - (0,0)x(viewbox.x, viewbox.y)
    Svg(Point viewbox);
    std::string file_name;
    // draw functions from canvas
    void polyline(std::vector<Point>, Properties prop) override;
    void line(Point pt1, Point pt2, Properties prop) override;
    void ellipse(Point center, double radiusx, double radiusy, Properties prop) override;
    void save(std::string file_name);

   private:
    Point viewbox;
    std::vector<Element> code;  // vectors with values for all the shapes we draw
    std::vector<std::string> strings;  // holds all the code that gets printed
    void get_viewbox(Point viewbox_point);
    std::vector<std::string> element_to_string();
    void svg_code(const Element&);  // takes in all the svg shape strings to format
    std::string polyline_points(Element e);  //
    std::string polyline_code(const Element& e);  // converts elements into specific svg strings
    std::string line_code(const Element& e);     // same as above
    std::string ellipse_code(const Element& e);  // same as above
    void end_code();  // prints the last line of svg code
};