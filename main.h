#ifndef MAIN_H
#define MAIN_H

#include "dictionary.h"
#include "heap.h"
#include "grid.h"
#include <sstream>
#include <string>

using namespace std;

//global functions
void checkDictionary(Dictionary &dict, const Grid &grid, int x, int y,
                     const int dirX, const int dirY);
void findMatches(Dictionary &dict, const Grid &grid);
void search();


//checks dictionary
void checkDictionary(Dictionary &dict, const Grid &grid, int x, int y,
                     const int dirX, const int dirY)
{
  const int minLen = 5;
  int gridSize = grid.mat.cols();
  const int first = 0;

  int row = x;
  int column = y;
  string letter = grid.mat[row][column];
  string word = letter;
  int cols = (int)grid.mat.cols();
  int ans;

  //search dictionary
  while (word.length() <= cols)
  {
    if (word.length() >= minLen)
    {
      // cout << "here" << endl;
      ans = dict.binarysearch(first, dict.length - 1, word);
      if (ans != -1)
      {
        cout << "Found: " << word << endl;
      }
    }
    row = row + dirX;
    column = column + dirY;

    if (row < 0)
      row = gridSize + row;
    if (row >= gridSize)
      row = row - gridSize;
    if (column < 0)
      column = gridSize + column;
    if (column >= gridSize)
      column = column - gridSize;
    letter = grid.mat[row][column];
    word = word + letter;
  }
}

//find matches 
void findMatches(Dictionary &dict, const Grid &grid)
{
  //go through the grid
  vector<int> range = {-1, 0, 1};
  for (int i = 0; i < grid.mat.cols(); i++)
  {
    for (int j = 0; j < grid.mat.cols(); j++)
    {
      for (auto x : range)
        for (auto y : range)
        {
          if (x == 0 && y == 0)
          {
          }
          else
          {
            checkDictionary(dict, grid, i, j, x, y); // my feeling is that
            // this line is not finishing for large dictionaries
          }
        }
    }
  }
}

//main function call
void search()
{
  // ofstream file;
  // file.open("sorteddictionary.txt");
  Grid grid;
  grid.read_letters();
  Dictionary dict;

  string selection;
  int input;

  while (true)
  {
    cout << "What Algorithm would you like to use? " << endl;
    cout << "1. Selection sort" << endl
         << "2. Quick sort" << endl
         << "3. Heap sort" << endl;
    getline(cin, selection);

    if (stringstream(selection) >> input)
    {
      if (input == 1)
      {
        cout << "You chose selection sort:" << endl;
        dict.sort();
      }
      else if (input == 2)
      {
        cout << "You chose quick sort:" << endl;
        dict.quicksort(0, dict.dictionary.size() - 1);
      }
      else if (input == 3)
      {
        cout << "You chose heap sort:" << endl;
        dict.heapsort();
      }
      break;
    }
    else
      cerr << "Incorrect Input." << endl;
  }

  // dict.quicksort(0, dict.dictionary.size() - 1);

  // cout << dict;
  cout << "\n\nMatches\n";
  findMatches(dict, grid);
  //     file.close();
  do
  {
    cout << '\n' << "Press the Enter key to continue...";
  } while (cin.get() != '\n');
}

#endif
