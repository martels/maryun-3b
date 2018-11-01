#ifndef DICTIONARY_H
#define	DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Dictionary
{
public:
    Dictionary();
	vector<string> dictionary;
    int length;
    int partition(int low, int high);
    void sort();
    void quicksort(int low, int high);
    bool search(int first, int last, string key);
    int binarysearch(int first, int last, string key);
	friend ostream& operator<< (ostream& ostr, const Dictionary& rhs);
};

#endif /* Dictionary_h */
