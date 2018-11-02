#ifndef grid_hpp
#define grid_hpp

#include "d_matrix.h"
#include <stdio.h>

//grid class descriptor
class Grid
{

public:
  void read_letters();
  matrix<string> mat;

private:
  int width;
  int length;
};

#endif /* Grid_hpp */
