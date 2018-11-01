#ifndef HEAP_H
#define HEAP_H

using namespace std;

template <typename T>
class Heap
{
public:
    vector<T> 
    
    Heap(const T& initVal = T());
    int parent(int index);
    int left(int index);
    int right(int index);
    T getItem(int n);
    void initialiseMaxHeap();
    void maxHeapify();
    void buildMaxHeap();
    void heapsort();
};

template <typename T>
Heap::Heap(const T& initialVal = T())
{

}

template <typename T> 
int Heap::parent(int index)
{

}

template <typename T>
int Heap::left(int index)
{

}

template <typename T>
int Heap::right(int index)
{

}

template <typename T>
T Heap::getItem(int n)
{

}

template <typename T>
void Heap::initialiseMaxHeap()
{

}

template <typename T>
void Heap::maxHeapify()
{

}

template <typename T>
void Heap::buildMaxHeap()
{

}

template <typename T>
void Heap::heapsort()
{

}
#endif