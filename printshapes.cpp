//Matt
#include "svg.h" 
#include <fstream>
#include <iostream>
#include <vector>
// include file with the vector
int main(){
    Point viewbox = {200,200};
    Svg canvas{viewbox};
    /*
    THIS IS ALL CODE THAT WE USED TO TEST - DISREGARD FRONTEND TEAM
    Point viewbox = {50,50};
    Svg file = {viewbox};
    

    //testing polyline
    Point p1 = {10, 20};
    Point p2 = {30, 40};
    Point p3 = {30, 10};
    Point p4 = {10, 20};
    std::vector<Point> points = {p1, p2, p3, p4};
    Properties properties;
    file.polyline(points, properties);

    //testing line
    Point p5 = {38, 43};
    Point p6 = {45, 49};
    Properties prop;
    file.line(p5, p6, prop);

    //testing ellipse
    Point p7 = {10,10};
    double radiusx = 5;
    double radiusy = 4;
    Properties propert;
    file.ellipse(p7, radiusx, radiusy, propert); */

    
    canvas.save("file.svg");
}

//create all of this to a save()- put in svg
//incorporate element_to_string()