#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <vector>

using namespace std;


//heap class descriptor
template <typename T>
class Heap
{
public:
  vector<T> heap;
  int heapsize;

  Heap(vector<T> vect);
  int parent(int index);
  int left(int index);
  int right(int index);
  T getItem(int n);
  void initialiseMaxHeap();
  void maxHeapify(int i);
  void buildMaxHeap();
  void heapsort();
};

template <typename T>
Heap<T>::Heap(vector<T> vect)
{
  heap = vector<T>(vect);
  heapsize = heap.size();
}

template <typename T>
int Heap<T>::parent(int index)
{
  double temp = (double)index;
  return ceil(temp / 2);
}

template <typename T>
int Heap<T>::left(int index)
{
  return index * 2;
}

template <typename T>
int Heap<T>::right(int index)
{
  return (index * 2) + 1;
}

template <typename T>
T Heap<T>::getItem(int n)
{
  return this->heap[n];
}

template <typename T>
void Heap<T>::initialiseMaxHeap()
{
}

//maintains heap status
template <typename T>
void Heap<T>::maxHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int largest;
  T temp;
  if (l <= heapsize && heap[l] > heap[i])
    largest = l;
  else
    largest = i;

  if (r <= heapsize && heap[r] > heap[largest])
    largest = r;
  if (largest != i)
  {
    cout << "here2" << endl;
    temp = this->heap[largest];
    this->heap[largest] = this->heap[i];
    this->heap[i] = this->heap[largest];
    maxHeapify(largest);
  }

}

//builds the heap
template <typename T>
void Heap<T>::buildMaxHeap()
{
  int size = heap.size();
  double temp = (double) size;
  for (int i = floor(temp / 2); i >= 1; i--)
  {
    maxHeapify(i); 
  }
}

//sorts the heap
template <typename T>
void Heap<T>::heapsort()
{
  T temp;
  buildMaxHeap();
   cout << "here1" << endl;
  for (int i = heap.size(); i >= 2; i--)
  {
    temp = heap[0];
    heap[0] = heap[i];
    heap[i] = temp;
    heapsize--;
    maxHeapify(0);
  }
  heapsize = heap.size();
}
#endif