#include "point.h"

Point::Point(int x, int y) : x(x), y(y) {}

int Point::get_x() { return x; }

int Point::get_y() { return y; }

Point Point::translate(Point dp) {
  Point p(x + dp.x, y + dp.y);
  return p;
}

Point Point::difference(Point p) {
  Point dp(-p.x, -p.y);
  return translate(dp);
}
