#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Array 
{
T* data;
int size;
int capacity;
int grow;

public:
    Array(int initialCapacity = 10, int growValue = 5) : size(0), capacity(initialCapacity), grow(growValue) 
    {
        data = new T[capacity];
    }

    ~Array() 
    {
        delete[] data;
    }

    int GetSize() const 
    {
        return size;
    }

    void SetSize(int newSize, int growValue = 1) 
    {
        if (newSize > capacity) 
        {
            int newCapacity = capacity + growValue;
            while (newCapacity < newSize) 
            {
                newCapacity += growValue;
            }
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) 
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        size = newSize;
    }

    int GetUpperBound() const 
    {
        return size - 1;
    }

    bool IsEmpty() const 
    {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) 
        {
            T* newData = new T[size];
            for (int i = 0; i < size; i++) 
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = size;
        }
    }

    void RemoveAll() 
    {
        size = 0;
    }

    T GetAt(int index) const 
    {
        if (index < 0 || index >= size) 
        {
            cout << "Error: Index out of range" << endl;
            return T(); 
        }
        return data[index];
    }

    void SetAt(int index, const T& value) 
    {
        if (index < 0 || index >= size) 
        {
            cout << "Error: Index out of range" << endl;
        }
        data[index] = value;
    }

    T& operator[](int index) 
    {
        if (index < 0 || index >= size) 
        {
            cout << "Error: Index out of range" << endl;
        }
        return data[index];
    }

    const T& operator[](int index) const 
    {
        if (index < 0 || index >= size) 
        {
            cout << "Error: Index out of range" << endl;
        }
        return data[index];
    }

    void Add(const T& value) 
    {
        if (size >= capacity) 
        {
            SetSize(size + grow);
        }
        data[size++] = value;
    }

    Array<T>& Append(const Array<T>& other) 
    {
        int newSize = size + other.size;
        if (newSize > capacity) 
        {
            int newCapacity = capacity + grow;
            while (newCapacity < newSize) 
            {
                newCapacity += grow;
            }
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) 
            {
                newData[i] = data[i];
            }
            for (int i = 0; i < other.size; i++) 
            {
                newData[size + i] = other.data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        else {
            for (int i = 0; i < other.size; i++) 
            {
                data[size + i] = other.data[i];
            }
        }
        size = newSize;
        return *this;
    }

    Array<T>& operator=(const Array<T>& other) 
    {
        if (this != &other) 
        {
            size = other.size;
            capacity = other.capacity;
            delete[] data;
            data = new T[capacity];
            for (int i = 0; i < size; i++) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() const 
    {
        return data;
    }

    void InsertAt(int index, const T& value) 
    {
        if (index < 0 || index > size) 
        {
            cout << "Error: Index out of range" << endl;
        }
        if (size >= capacity) 
        {
            SetSize(size + grow);
        }
        for (int i = size; i > index; i--) 
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void RemoveAt(int index) 
    {
        if (index < 0 || index >= size) 
        {
            cout << "Error: Index out of range" << endl;
        }
        for (int i = index; i < size - 1; i++) 
        {
            data[i] = data[i + 1];
        }
        size--;
    }
};