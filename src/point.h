#pragma once

class Point {
 private:
  int x;
  int y;

 public:
  Point(int x, int y);

  int get_x();

  int get_y();

  Point translate(Point dp);

  Point difference(Point p);
};
