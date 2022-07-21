# SVG-Group-Project: 
Built a program collaboratively with one other group of students to draw pictures using Scalable Vector Graphics (SVG) in HTML. The language used to produce these XML text files was C++. 
Worked on a team of 3 students to provide resuable functions to create pictures using SVG/XML.
My group focused on creating functions to support creation of  ellipses, rectangles and polygons.
![Screenshot}(svgfile1.png)
![Screenshot}(svgfile2.png)
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
# Frontend Team Guide
**Purpose:** We provide classes that allow you to draw regular polygons, rectangles, ellipses, lines, and tiled hexagons

## Points
This code relies on coordinates for the placement of shapes using a struct called **Point**. **Point** takes in two *doubles*, and the first number will be the X coordinate and the second number will be the Y coordinate
### Example:
```C++
Point center = {500, 300};
```

## Before drawing any shape:
1. Create a **Point** that will determine the size of your *viewbox*. Whatever numbers you choose for the X and Y coordinates will be the size of your *viewbox*. If you are unsure how big to make it, 1500 x 800 is a decent size to start with
    
    #### Examples:
    ```C++
    Point viewbox = {1500, 800};
     ```
     ```C++
    Point viewbox = {2000, 1000};
    ```
2. Create an svg and pass in viewbox
    ```C++
    Svg svg(viewbox);
    ```
3. Figure out where you would like to place each shape. Every shape takes in a **Point** that will be the center point coordinate that determines where the shape will be placed

## Shape Class
This is the base class for classes **Line**, **Rectangle**, **Ellipse**, and **Reg-poly**. All these shapes have a **Point** center_point. These shapes also can call three functions to set the fill color, edge color, and the opacity. To learn about them, reference the changing color and opacity section. You cannot draw a pure **Shape**, though, only classes that inherit from it.

## Properties Struct
This struct contains three variables, stroke, fill, and opacity. The default stroke and fill color is set to black, and the default opacity is 1.0.


## Lines
To create a line, use the **Line** class and pass in one **Point** as the beginning coordinate and one **Point** as the ending coordinate. To draw your line, please reference the drawing section
### Examples:
```C++
Line line = {Point{4, 5}, Point{100, 400}};
```
## Rectangles
To create a rectangle, use the **Rectangle** class and pass in a **Point** that will be the center point coordinate, a *double* to determine the X length (width), and a *double* to determine the Y length (height). To draw your rectangle, please reference the drawing section
### Examples:
```C++
Rectangle rect = {Point{700, 400}, 100, 75};
```
```C++
Point center = {500, 700};
Rectangle square = {center, 80, 80};
```

## Ellipse
To create an ellipse, use the **Ellipse** class and pass in a **Point** that will be the center point coordinate, a *double* to determine the size of the X radius, and a *double* to determine the size of the Y radius. To draw your ellipse, please reference the drawing section

### Examples:
```C++
Point center = {500, 450};
Ellipse circle = {center, 50, 50};
```
```C++
Ellipse oval = {Point{400, 300}, 100, 70};
```

## Regular Polygons
To create a regular polygon, use the **Reg_poly** class and pass in a **Point** that will be the center point coordinate, an *integer* to determine the number of sides your regular polygon will have, and an *integer* to determine the length of each side. To draw your regular polygon, please reference the drawing section

### Examples:
```C++
Point center = {500, 500};
Reg_poly hexagon = {center, 6, 50};
```
```C++
Reg_poly triangle = {Point{300, 250}, 3, 75};
```

## Tiled Hexagons
To create a pattern of tiled hexagons, use the **Hex_tiles** class and pass in an *integer* to determine the side length of each hexagon, a *double* for the size the gap between each hexagon, and your ***viewbox*** **Point**. To draw your tiled hexagons, please reference the drawing section
### Examples:
```C++
Hex_tiles hex_tiles = {50, 10, viewbox};
```
```C++
Hex_tiles hexagons = {25, 5, viewbox};
```

## Changing Color and Opacity
### Functions:
1. **set_fill_color(std::string color)**
2. **set_edge_color(std::string color)**
3. **set_opacity(double opacity)**

You can change the fill color, edge color, and the opacity of each shape (except lines and hex tiles) by calling the functions **set_fill_color()**, **set_edge_color()**, and **set_opacity()**. If you don't decide to use these functions, the fill color and edge color will default to black, and the default opacity is 1.0 (fully opaque). The **set_fill_color()** and **set_edge_color()** functions both take in a *string* to determine the color, and **set_opacity** takes in a double ranging from 0.0 (completely transparent) to 1.0 (completely opaque)

Hexagon tiles have to use their own functions to change the color and opacity, which is explained further in the ***Changing Color of Hexagon Tiles*** section below. For lines, the **set_fill_color()** function does nothing because there is no inside to fill with color. To color a line, just use **set_edge_color()**

### Examples:
```C++
Reg_poly hex = {Point{400, 300}, 6, 50};
hex.set_fill_color("blue");
hex.set_edge_color("blue");
```
```C++
Point center = {500, 500};
Rectangle square = {center, 70, 70};
square.set_opacity(0.5);
```


## Changing Color of Hexagon Tiles
The *set_fill_color()*, *set_edge_color()*, and *set_opacity()* functions won't work for hexagon tiles. Instead you'll have to use **set_hex_color()** and **set_hex_opacity()** for hex tiles
### Examples:
```C++
Hex_tiles hex_tiles = {40, 5, viewbox};
hex_tiles.set_hex_color("blue");
```
```C++
Hex_tiles hexagons = {75, 10, viewbox};
hexagons.set_hex_opacity(0.5);
```

## Creating a Background
If you want a background color, create a rectangle the size of your viewbox with the center point being in the middle of the viewbox. Make sure to create this shape ***first*** so it will actually be in the background and not cover the rest of your shapes!
### Examples:
```C++
Point viewbox = {1500, 800};
Svg svg(viewbox);

Point background_center = {viewbox.x / 2, viewbox.y / 2};
Rectangle background = {background_center, viewbox.x, viewbox.y};
background.set_fill_color("lime");
background.draw(svg);
```
```C++
Point viewbox = {2000, 1000};
Svg svg(viewbox);

Rectangle background = {Point{1000, 500}, 2000, 1000};
background.set_fill_color("blue");
background.draw(svg);
```


## Drawing shapes
1. Make your shape(s)
2. Change the color, edge color, and opacity of each shape (if desired)
3. Call the *draw* function for each shape and pass in **svg**
4. At the ***END***, save the file by calling the *save* function in **svg** and pass in a *string* of what you want to call the file, followed by ***.svg***
    ```C++
    svg.save("shapes.svg");
    ```
5. Compile & look at your new svg 
### Examples:
```C++
Point center = {500, 500};
Reg_poly hexagon = {center, 6, 50};
hexagon.set_fill_color("lime");
hexagon.draw(svg);
svg.save("hexagon.svg");
```
```C++
Ellipse oval = {Point{400, 300}, 100, 70};
oval.draw(svg);
svg.save("oval.svg");
```
```C++
Point background_center = {viewbox.x / 2, viewbox.y / 2};
Rectangle background = {background_center, viewbox.x, viewbox.y};
background.set_fill_color("red");
background.draw(svg);

Hex_tiles hex_tiles = {50, 5, viewbox};
hex_tiles.draw(svg);
svg.save("hex_tiles.svg");
```
