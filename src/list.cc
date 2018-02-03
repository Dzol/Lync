#include "list.h"

/************
 * Sentinel *
 ************/

Sentinel::Sentinel() {};

int Sentinel::fold(int seed, int (*function) (int, int)) {
  return seed;
}

/********
 * Cell *
 ********/

Cell::Cell(int h, List* t) {
  _head = h; _tail = t;
}

int Cell::fold(int seed, int (*function) (int, int)) {
  return _tail->fold(function(seed, _head), function);
}

int Cell::head() {
  return _head;
}

List* Cell::tail() {
  return _tail;
}
