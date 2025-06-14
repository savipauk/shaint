#pragma once

#include "point.h"

class Renderer {
 public:
  virtual void draw_line(Point s, Point e) = 0;
  virtual void fill_polygon(Point points[]) = 0;
};
