#pragma once

#include "abstract_graphical_object.h"

class LineSegment : public AbstractGraphicalObject {
 public:
  LineSegment();
  LineSegment(Point p1, Point p2);

  Rectangle get_bounding_box() override;
  double selection_distance(Point mouse_point) override;
  std::string get_shape_name() override;
  GraphicalObject* duplicate() override;
};
