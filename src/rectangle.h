#pragma once

class Rectangle {
 private:
  int x;
  int y;
  int width;
  int height;

 public:
  Rectangle(int x, int y, int width, int height);

  int get_x();

  int get_y();

  int get_width();

  int get_height();
};
