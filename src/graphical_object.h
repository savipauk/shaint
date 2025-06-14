#pragma once

#include <SDL_events.h>

#include <stack>
#include <string>
#include <vector>

#include "point.h"
#include "rectangle.h"
#include "renderer.h"

class GraphicalObjectListener;

class GraphicalObject {
 public:
  virtual ~GraphicalObject() {}
  // virtual void draw() = 0;
  // virtual void event(const SDL_Event& e) {}

  virtual bool is_selected() = 0;
  virtual void set_selected(bool selected) = 0;

  virtual int get_number_of_hot_points() = 0;
  virtual Point get_hot_point(int index) = 0;
  virtual void set_hot_point(int index, Point point) = 0;
  virtual bool is_hot_point_selected(int index) = 0;
  virtual void set_hot_point_selected(int index, bool selected) = 0;
  virtual double get_hot_point_distance(int index, Point mouse_point) = 0;

  virtual void translate(Point delta) = 0;
  virtual Rectangle get_bounding_box() = 0;
  virtual double selection_distance(Point mouse_point) = 0;

  virtual void add_graphical_object_listener(GraphicalObjectListener* l) = 0;
  virtual void remove_graphical_object_listener(GraphicalObjectListener* l) = 0;

  virtual std::string get_shape_name() = 0;
  virtual GraphicalObject* duplicate() = 0;

  // virtual std::string get_shape_id() = 0;
  // virtual void load(std::stack<GraphicalObject*>& stack, std::string data) = 0;
  // virtual void save(std::vector<std::string> rows) = 0;
};
