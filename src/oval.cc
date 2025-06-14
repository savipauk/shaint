#include "oval.h"

#include "common.h"

Oval::Oval() : AbstractGraphicalObject({Point(10, 0), Point(0, 10)}) {}

Oval::Oval(Point p1, Point p2) : AbstractGraphicalObject({p1, p2}) {}

Rectangle Oval::get_bounding_box() {
  int width = std::abs(get_hot_point(0).get_x() - get_hot_point(1).get_x());
  int height = std::abs(get_hot_point(0).get_y() - get_hot_point(1).get_y());
  Rectangle rect(get_hot_point(0).get_x(), get_hot_point(1).get_y(), width,
                 height);
  return rect;
}

double Oval::selection_distance(Point mouse_point) {
  Point midpoint((get_hot_point(0).get_x() + get_hot_point(1).get_x()) / 2,
                 (get_hot_point(0).get_y() + get_hot_point(1).get_y()) / 2);
  return GeometryUtil::distance_from_point(midpoint, mouse_point);
}

std::string Oval::get_shape_name() { return "Oval"; }

GraphicalObject* Oval::duplicate() {
  return new Oval(get_hot_point(0), get_hot_point(1));
}
