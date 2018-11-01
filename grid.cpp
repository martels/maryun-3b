#include "grid.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Grid::read_letters()
{
    string file;
    cout << "Which file would you like to open?" << endl;
    getline(cin, file);
    
    ifstream grid_file;
    grid_file.open(file);
    grid_file >> width >> length;
    mat.resize(width, length);
    
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
           grid_file >> mat[i][j];
           
        }
    }
    grid_file.close();
}
