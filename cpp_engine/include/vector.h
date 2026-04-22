#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class T>
class vector
{
    int capacity;
    T *arr;
    int sz;

public:
    vector()
    {
        capacity = 1;
        sz = 0;
        arr = new T[capacity];
    }

    void push_back(T val)
    {
        if (sz == capacity)
        {
            capacity *= 2;
            T *newArr = new T[capacity];
            for (int i = 0; i < sz; ++i)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[sz++] = val;
    }

    T pop_back()
    {
        if (empty())
        {
            std::cout << "VECTOR EMPTY\n";
            return T();
        }
        return arr[--sz];
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= sz)
        {
            std::cout << "INDEX OUT OF BOUND\n";
            exit(1);
        }
        return arr[index];
    }

    T &back()
    {
        if (empty())
        {
            std::cout << "VECTOR EMPTY\n";
            exit(1);
        }
        return arr[sz - 1];
    }

    bool empty()
    {
        return (sz == 0);
    }

    int size()
    {
        return sz;
    }

    ~vector()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }
};

#endif