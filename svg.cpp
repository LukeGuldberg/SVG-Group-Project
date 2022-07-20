#include "svg.h"

#include <fstream>
#include <iostream>
#include <vector>
// Luke
// Sets Canvas size to (0,0)x(viewbox.x, viewbox.y)
Svg::Svg(Point viewbox) : viewbox{viewbox} {} 
// Luke
// takes in two (x,y) Points and makes a line element.
void Svg::line(Point pt1, Point pt2, Properties prop) {
    Element element = {"line", pt1, pt2, prop};
    Svg::code.push_back(element);
}
// Matt
//  takes in an (x,y) Point and two radii needed and makes an ellipse element.
void Svg::ellipse(Point center, double radiusx, double radiusy,
                  Properties prop) {
    Element element = {"ellipse", center, radiusx, radiusy, prop};
    Svg::code.push_back(element);
}

// Jaxon
// takes in a vector of (x,y) Points that are the endpoints of the shapes, then makes a polyline element.
void Svg::polyline(std::vector<Point> points, Properties prop) {
    Element element = {"polyline", points, prop};
    Svg::code.push_back(element);
}
// Luke
// takes in all the svg shape strings and uses the for loop
std::vector<std::string> Svg::element_to_string() {
    // get the viewbox
    get_viewbox(viewbox);

    for (Element e :
         Svg::code) {  // iterate over all the elements (lines of string that
                       // draws shapes) then pushback to vector<string>
        svg_code(e);
    }

    end_code();
    return strings;
}
// Luke
// sets the drawing canvass height and width starting at (0,0) going to an (x,y)
// Point, this also prints the first line of our svt file.
void Svg::get_viewbox(Point point) {
    std::string line = "<svg Viewbox = \"0 0 " + std::to_string(point.x) + " " +
                       std::to_string(point.y) +
                       "\" xmlns= \"http://www.w3.org/2000/svg\">\n";
    Svg::strings.push_back(line);
}
// Luke
// Jaxon
// first the function decides what shape is being written, then it pushes back the concatenated strings into the vector.
void Svg::svg_code(const Element& e) {
    if (e.type == "polyline") {
        Svg::strings.push_back(polyline_code(e));
    } else if (e.type == "ellipse") {
        Svg::strings.push_back(ellipse_code(e));
    } else if (e.type == "line") {
        Svg::strings.push_back(line_code(e));
    } else {
        throw std::runtime_error("Type not recognized");
    }
}
// Luke
// takes in all the (x,y) Points for a specific polyline shape, then formats them to fit the svg code.
std::string Svg::polyline_points(Element e) {
    std::string list;
    for (Point p :
         e.pts) {  // itterate over the vector of Points for a single polyline
        std::string newpoint =
            std::to_string(p.x) + "," + std::to_string(p.y) + " ";
        list += newpoint;
    }
    return list;
}
// Jaxon
// turning an element (polyline) into svg code by concatenating all the values the element holds.
std::string Svg::polyline_code(const Element& e) {
    return "\t<" + e.type + " points=\"" + polyline_points(e) + "\" fill=\"" +
           e.prop.fill + " \" stroke=\"" + e.prop.stroke + "\" />\n";
}
// Luke
// turning an element (line) into svg code by concatenating all the values the element holds.
std::string Svg::line_code(const Element& e) {
    return "\t<" + e.type + " x1=\"" + std::to_string(e.pt1.x) + "\" y1=\"" +
           std::to_string(e.pt1.y) + "\" x2=\"" + std::to_string(e.pt2.x) +
           "\" y2=\"" + std::to_string(e.pt2.y) + "\" stroke=\"" +
           e.prop.stroke + "\" />\n";
}
// Matt
// turning an element (ellipse) into svg code by concatenating all the values the element holds.
std::string Svg::ellipse_code(const Element& e) {
    return "\t<" + e.type + " cx= \"" + std::to_string(e.center.x) +
           "\" cy= \"" + std::to_string(e.center.y) + "\" rx= \"" +
           std::to_string(e.radiusx) + "\" ry= \"" + std::to_string(e.radiusy) +
           "\" fill= \"" + e.prop.fill + " \" stroke= \"" + e.prop.stroke +
           "\"/>\n";
}
// Luke
// simply writes the last line of svg code to end the file.
void Svg::end_code() { Svg::strings.push_back("</svg>"); }
// Matt
// this saves the svg strings we created and then writes those to a file one by one.
void Svg::save(std::string file_name) {
    std::ofstream ostrm{file_name};

    std::vector<std::string> string = element_to_string();

    for (std::string s : string) {
        ostrm << s;
    }
}