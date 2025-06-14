#include "abstract_graphical_object.h"

#include <algorithm>

#include "common.h"

AbstractGraphicalObject::AbstractGraphicalObject(std::vector<Point> hot_points)
    : hot_points(std::move(hot_points)),
      hot_point_selected(hot_points.size(), false),
      selected(false) {}

Point AbstractGraphicalObject::get_hot_point(int i) { return hot_points[i]; }

void AbstractGraphicalObject::set_hot_point(int i, Point p) {
  hot_points[i] = p;
  notify_listeners();
}

int AbstractGraphicalObject::get_number_of_hot_points() {
  return (int)hot_points.size();
}

double AbstractGraphicalObject::get_hot_point_distance(int i, Point p) {
  return GeometryUtil::distance_from_point(hot_points[i], p);
}

bool AbstractGraphicalObject::is_hot_point_selected(int i) {
  return hot_point_selected[i];
}

void AbstractGraphicalObject::set_hot_point_selected(int i, bool selected) {
  hot_point_selected[i] = selected;
  notify_selection_listeners();
}

bool AbstractGraphicalObject::is_selected() { return selected; }

void AbstractGraphicalObject::set_selected(bool sel) {
  selected = sel;
  notify_selection_listeners();
}

void AbstractGraphicalObject::translate(Point delta) {
  for (auto& pt : hot_points) {
    pt.translate(delta);
  }
  notify_listeners();
}

void AbstractGraphicalObject::add_graphical_object_listener(
    GraphicalObjectListener* l) {
  listeners.push_back(l);
}

void AbstractGraphicalObject::remove_graphical_object_listener(
    GraphicalObjectListener* l) {
  listeners.erase(std::remove(listeners.begin(), listeners.end(), l),
                  listeners.end());
}

void AbstractGraphicalObject::notify_listeners() {
  for (auto* l : listeners) {
    l->graphical_object_changed(*this);
  }
}

void AbstractGraphicalObject::notify_selection_listeners() {
  for (auto* l : listeners) {
    l->graphical_object_selection_changed(*this);
  }
}
