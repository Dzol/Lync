#ifndef LIST_H
#define LIST_H

class List {
public:
  virtual int fold(int, int (*) (int, int)) = 0;
};

class Sentinel : public List {
public:
  Sentinel(); ~Sentinel(); //
  int fold(int, int (*) (int, int));
};

class Cell : public List {
  int _head; List* _tail;
public:
  Cell(int, List*); ~Cell(); //
  int fold(int, int (*) (int, int));
  int head(); List* tail();
};

#endif
