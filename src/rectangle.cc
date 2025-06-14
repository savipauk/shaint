#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

int Rectangle::get_x() { return x; }

int Rectangle::get_y() { return y; }

int Rectangle::get_width() { return width; }

int Rectangle::get_height() { return height; }
