#include "line_segment.h"
#include "common.h"

LineSegment::LineSegment()
    : AbstractGraphicalObject({Point(0, 0), Point(10, 0)}) {}

LineSegment::LineSegment(Point p1, Point p2)
    : AbstractGraphicalObject({p1, p2}) {}

Rectangle LineSegment::get_bounding_box() {
  int width = std::abs(get_hot_point(0).get_x() - get_hot_point(1).get_x());
  int height = std::abs(get_hot_point(0).get_y() - get_hot_point(1).get_y());
  Rectangle rect(get_hot_point(0).get_x(), get_hot_point(1).get_y(), width,
                 height);
  return rect;
}

double LineSegment::selection_distance(Point mouse_point) {
  Point midpoint((get_hot_point(0).get_x() + get_hot_point(1).get_x()) / 2,
                 (get_hot_point(0).get_y() + get_hot_point(1).get_y()) / 2);
  return GeometryUtil::distance_from_point(midpoint, mouse_point);
}

std::string LineSegment::get_shape_name() { return "Linija"; }

GraphicalObject* LineSegment::duplicate() {
  return new LineSegment(get_hot_point(0), get_hot_point(1));
}
