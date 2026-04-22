#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack
{
    int capacity;
    T *arr;
    int topIdx;

public:
    Stack()
    {
        capacity = 1;
        topIdx = -1;
        arr = new T[capacity];
    }

    void push(T val)
    {
        if (topIdx == capacity - 1)
        {
            capacity *= 2;
            T *newArr = new T[capacity];
            for (int i = 0; i <= topIdx; ++i)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[++topIdx] = val;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "STACK UNDERFLOW\n";
            return;
        }
        topIdx--;
    }

    T peek()
    {
        if (isEmpty())
        {
            std::cout << "STACK UNDERFLOW\n";
            return T();
        }
        return arr[topIdx];
    }

    bool isEmpty()
    {
        return (topIdx == -1);
    }

    int size()
    {
        return topIdx + 1;
    }

    ~Stack()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }
};

#endif