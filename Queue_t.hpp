

#ifndef Queue_t_hpp
#define Queue_t_hpp

#include <stdio.h>
#include "Queue_t.hpp"

template<typename T>
class Queue_t
{
public:
    Queue_t(int size);
    ~Queue_t();
    bool enqueue(T el);
    bool dequeue(T& el);
    bool isEmpty();
private:
    T* arr;
    int top;
    int size;
    
};
template<typename T>
Queue_t<T>::Queue_t(int size)
{
    this->size = size;
    top = 0;
    arr = new T[size];
}

template<typename T>
Queue_t<T>::~Queue_t()
{
    delete[] arr;
}

template<typename T>
bool Queue_t<T>::enqueue(T el)
{
    if (top < size)
    {
        arr[top++] = el;
        return true;
    }
    else
        return false;
}

template<typename T>
bool Queue_t<T>::dequeue(T& el)
{
    if (top > 0)
    {
        el = arr[0];
        for (int i = 0;i < top-1;i++)
            arr[i] = arr[i + 1];
        top--;
        return true;
    }
    else
        return false;
}

template<typename T>
bool Queue_t<T>::isEmpty()
{
    return top == 0;
}


#endif /* Queue_t_hpp */
