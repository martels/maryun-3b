#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include "d_matrix.h"

class Grid{
    
public:
    void read_letters();
    matrix<string> mat;
    
private:
    int width;
    int length;
};


#endif /* Grid_hpp */
