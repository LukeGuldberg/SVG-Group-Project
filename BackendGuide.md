# Backend Team SVG Guide 
## Default Constructor
```C++
class Svg : public Canvas {
    Svg(Point viewbox);
```
* ### By default the size starts at (0,0) then takes in an x and a y value to set the height and width of the canvas you will be drawing on.
Note that all functions following this code are also member functions of ```class Svg```.

## Properties Struct
```C++
struct Properties {
    std::string stroke{"black"};
    std::string fill {"black"};
    double opacity {1.0};
};
```
* ### Each value has a default setting so that you can just create Property and not have to set any values if you don't want to.
```C++
Properties default; //default.opacity == 1.0
```
## Draw functions
```C++
    void Svg::polyline(std::vector<Point>, Properties prop) override;
    void Svg::line(Point pt1, Point pt2, Properties prop) override;
    void svg::ellipse(Point center, double radiusx, double radiusy,  Properties prop) override;
```
* ### Polyline is used to connect any number of points (drawing polygons). You pass in a vector of Points and some value for Properties
* ### Line is used for anything that only has two points.
* ### Ellipse is used to print any round shape. It is important to remember a circle is an ellipse, but an ellipse is not a circle. There for when you enter ```double radiusx``` and ```double radiusy``` as the same length, you will get a circle around the ```Point center```.


## Save SVG Code to a File
```C++
void Svg::save(std::string file_name);
```
* ### The final step that actually puts your shapes onto the canvas. Creates a _.svg file that holds the SVG code for each of the shapes you created. 