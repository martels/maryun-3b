#ifndef HEAP_H
#define HEAP_H
#include <cmath>

using namespace std;

template <typename T>
class Heap
{
public:
  *vector<T> heap;
  int heapsize;

  Heap(const T &initVal = T());
  int parent(int index);
  int left(int index);
  int right(int index);
  T getItem(int n);
  int void initialiseMaxHeap();
  void maxHeapify();
  void buildMaxHeap();
  void heapsort();
};

template <typename T>
Heap::Heap(const T &initialVal = T())
{
    heap = new vector<T> (initialVal);
    heapsize = heap.size();
}

template <typename T>
int Heap::parent(int index)
{
  double temp = (double)index;
  return ceil(index / 2);
}

template <typename T>
int Heap::left(int index)
{
  return index * 2;
}

template <typename T>
int Heap::right(int index)
{
  return (index * 2) + 1;
}

template <typename T>
T Heap::getItem(int n)
{
  return this->heap[n];
}

template <typename T>
void Heap::initialiseMaxHeap()
{
}

template <typename T>
void Heap::maxHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  T temp;
  if (l <= heapsize && heap[r] > heap[i])
    largest = 1;
  else
    largest = r;

  if (r <= heapsize && heap[r] > heap[largest])
    largest = r;
  if (largest != i)
  {
    temp = this->heap[largest];
    this->heap[largest] = this->heap[i];
    this->heap[i] = this->heap[largest];
    maxHeapify(largest);
  }
}

template <typename T>
void Heap::buildMaxHeap()
{
  for (int i = floor(size / 2); i >= 1; i--)
  {
      maxHeapify(i);
  }
}

template <typename T>
void Heap::heapsort()
{
    T temp;
    heapsize = heap.size();
    buildMaxHeap();
    for(int i = heap.size(); i >= 2; i--)
    {
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;
        heapsize - 1;
        maxHeapify();
    }
    heapsize = heap.size();
}
#endif