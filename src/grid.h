#pragma once
#include <vector>
#include <raylib.h>

class Grid {
private:
  int rows;
  int cols;
  int cell_size;

public:
Grid(int r, int c, int cellsize);
  void init();
  void print();
  void draw();
  std::vector<Color> colors;
  int grid[20][10];
};



