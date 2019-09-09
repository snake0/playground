//
// Created by SNAKE on 2019-09-08.
//

#ifndef LEETCODE_INTCELL_H
#define LEETCODE_INTCELL_H


class IntCell {
 public:
  explicit IntCell(int initialValue = 0);
  ~IntCell();
  IntCell(const IntCell& rhs);
  IntCell(IntCell&& rhs);
  IntCell& operator=(const IntCell& rhs);
  IntCell& operator=(IntCell&& rhs);

  int read() const;
  void write(int x);
 private:
  int* storedValue;
};


#endif //LEETCODE_INTCELL_H
