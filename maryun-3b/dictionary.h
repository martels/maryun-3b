#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//dictionary class descriptor
class Dictionary
{
public:
  Dictionary();
  vector<string> dictionary;
  int length;
  int partition(int low, int high);
    //sorting functions
  void sort();
  void quicksort(int low, int high);
  void heapsort();
    //searching functions
  bool search(int first, int last, string key);
  int binarysearch(int first, int last, string key);
  friend ostream &operator<<(ostream &ostr, const Dictionary &rhs);
};

#endif /* Dictionary_h */
