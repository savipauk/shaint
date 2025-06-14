#pragma once

#include "graphical_object.h"

class AbstractGraphicalObject : public GraphicalObject {
 private:
  std::vector<Point> hot_points;
  std::vector<bool> hot_point_selected;
  bool selected;
  std::vector<GraphicalObjectListener*> listeners;

 public:
  AbstractGraphicalObject(std::vector<Point> hot_points);

  Point get_hot_point(int i) override;
  void set_hot_point(int i, Point p) override;
  int get_number_of_hot_points() override;
  double get_hot_point_distance(int i, Point p) override;
  bool is_hot_point_selected(int i) override;
  void set_hot_point_selected(int i, bool state) override;
  bool is_selected() override;
  void set_selected(bool state) override;
  void translate(Point p) override;
  void add_graphical_object_listener(GraphicalObjectListener* gol) override;
  void remove_graphical_object_listener(GraphicalObjectListener* gol) override;
  void notify_listeners();
  void notify_selection_listeners();
};
