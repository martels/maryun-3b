#include "dictionary.h"
#include "heap.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

Dictionary::Dictionary()
{
	length = 0;
	ifstream dictionaryfile;
	dictionaryfile.open("dictionary.txt");

	//Error Checking
	if(dictionaryfile.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	string str;
	while(dictionaryfile >> str) // while(getline(dictionaryfile, str)) 
	{
	    if (str.size() > 0) 
	    {
	    	dictionary.push_back(str);
	        length++;
	    }
	}

	dictionaryfile.close();
}


void Dictionary::sort()
{
    int current;
	string temp;
	int length = dictionary.size();
	double percent = 0;

    for(int i = 0; i< length-1; i++)
	{
		current = i;
        for(int j = i+1; j<length; j++)
		{
			if(dictionary[j] < dictionary[current])
			{
				current = j;
			}
		}
		temp = dictionary[i];
		dictionary[i] = dictionary[current];
		dictionary[current] = temp;

		percent = (i*100/length);
		cout << "Sorting(" << percent << "%) \r" << flush;
	}
	cout << "Sorting(100%)" << endl;
	return;
}

void Dictionary::heapsort()
{
	Heap<string> heap(dictionary);
	heap.heapsort();
	dictionary = heap.heap;
}

int Dictionary::partition(int low, int high)
{
	int i = (low -1);
	string pivot = dictionary[high];
	string temp;

	for(int j = low; j <= high - 1; j++)
	{
		if(dictionary[j] <= pivot)
		{
			i++;
			temp = dictionary[i];
			dictionary[i] = dictionary[j];
			dictionary[j] = temp;
		}
	}

	temp = dictionary[i+1];
	dictionary[i+1] = dictionary[high];
	dictionary[high] = temp;
	return (i + 1);
}


void Dictionary::quicksort(int low, int high)
{
	int pi;
	if(low < high)
	{
		pi = partition(low, high);

		quicksort(low, pi - 1);
		quicksort(pi + 1, high);
	}
}

bool Dictionary::search(int first, int last, string key)
{
//    int compare;
    
    if (first == last)
    {
    	if(key.compare(dictionary[first]) == 0)
        	return true;
        else
        	return false;
    }
    
	while(first <= last)
	{
		int mid = (first + last) / 2;
        //compare = key.compare(dictionary[mid]);
        //cout << compare << endl;
        
        if(dictionary[mid] == key)
        {
            return true;
        }
        
		else if(key < dictionary[mid])
		{
			last = mid - 1;;
		}
        
		else
		{
            first = mid + 1;
		}
	}
	return false;
}

int Dictionary::binarysearch(int first, int last, string key)
{
	if(last >= first)
	{
		int mid = (first + last) / 2;
		//cout << mid << " ";
		if(key == dictionary[mid])
			return mid;

		if (dictionary[mid] > key)
			return binarysearch(first, mid - 1, key);
		else
			return binarysearch(mid + 1, last, key);
	}
// it isnt working correctly still
	return -1;
}

ostream& operator<<(ostream& ostr, const Dictionary& rhs)
{
	int size = rhs.dictionary.size();
	for(int i = 0; i < size; i++)
	{
		ostr << rhs.dictionary.at(i) << endl;
	}
	return ostr;
}


