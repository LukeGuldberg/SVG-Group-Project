// Luke
// Jaxon
#include "Element.h"


Element::Element(std::string type, std::vector<Point> pts, Properties prop) // polyline constructor
    :type{type}, pts{pts}, prop{prop}{}
Element::Element(std::string type, Point pt1, Point pt2, Properties prop) // line constructor
    :type{type},pt1{pt1}, pt2{pt2}, prop{prop}{}
Element::Element(std::string type, Point center, double radiusx, double radiusy, Properties prop) //ellipse constructor
    :type{type}, center{center}, radiusx{radiusx}, radiusy{radiusy}, prop{prop}{}