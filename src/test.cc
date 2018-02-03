#include <iostream>
#include <cassert>
#include "list.h"

int sum(int seed, int element) {
  return seed + element;
}

int print(int seed, int element) {
  std::cout << seed++ << ":" << " " << element << "\n";
  return seed;
}

List* construct(int head, List* tail) {
  return new Cell(head, tail);
}

void test() {

  List* l = new Sentinel();
  for (int i = 5; i > 0; i--)
    l = construct(i, l);

  int s = l->fold(0, &sum);
  std::cout << "sum:" << " " << s << "\n";
  assert (s == 15);

  int x = l->fold(0, &print);
  assert (x == 5);
}

int main() {
  test(); return 0;
}
