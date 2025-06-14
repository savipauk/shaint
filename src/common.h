#pragma once

#include <cmath>

#include "graphical_object.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TARGET_FPS 60

struct Vec2 {
  int x;
  int y;
};

class GraphicalObjectListener {
 public:
  virtual void graphical_object_changed(GraphicalObject& go) = 0;
  virtual void graphical_object_selection_changed(GraphicalObject& go) = 0;
};

class GeometryUtil {
 public:
  static double distance_from_point(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.get_x() - p1.get_x(), 2) +
                     std::pow(p2.get_y() - p1.get_y(), 2));
  }

  static double distance_from_line_segment(Point s, Point e, Point p) {
    int se_x = e.get_x() - s.get_x();
    int se_y = e.get_y() - s.get_y();

    int sp_x = p.get_x() - s.get_x();
    int sp_y = p.get_y() - s.get_y();

    int dot = se_x * sp_x + se_y * sp_y;
    int len = std::pow(se_x, 2) + std::pow(se_y, 2);
    double t = len > 0 ? (double)dot / (double)len : -1;

    if (t < 0.0) {
      return std::hypot(p.get_x() - s.get_x(), p.get_y() - s.get_y());
    } else if (t > 1.0) {
      return std::hypot(p.get_x() - e.get_x(), p.get_y() - e.get_y());
    }

    double projection_x = s.get_x() + t * se_x;
    double projection_y = s.get_y() + t * se_y;

    return std::hypot(p.get_x() - projection_x, p.get_y() - projection_y);
  }
};

class Location {
 public:
  int x;
  int y;

  Location(int line = 0, int column = 0) : x(line), y(column) {}

  bool operator==(const Location& other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const Location& other) const { return !(*this == other); }

  bool operator<(const Location& other) {
    return (y < other.y) || (y == other.y && x < other.x);
  }
};

class LocationRange {
 public:
  Location start;
  Location end;

  LocationRange(const Location& start, const Location& end)
      : start(start), end(end) {}
};

class CursorObserver {
 public:
  virtual ~CursorObserver() = default;
  virtual void update_cursor_location(const Location& loc) = 0;
};

class TextObserver {
 public:
  virtual ~TextObserver() = default;
  virtual void update_text() = 0;
};
