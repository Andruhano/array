#include "Array.h"


int main() 
{
    Array<int> arr;
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);

    cout << "Array size: " << arr.GetSize() << endl;
    cout << "Array content: ";
    for (int i = 0; i < arr.GetSize(); i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.Add(4);
    cout << "Array content after adding 4: ";
    for (int i = 0; i < arr.GetSize(); i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.InsertAt(1, 10);
    cout << "Array content after inserting 10 at index 1: ";
    for (int i = 0; i < arr.GetSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAt(2);
    cout << "Array content after removing element at index 2: ";
    for (int i = 0; i < arr.GetSize(); i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAll();
    cout << "Deleting data" << endl;
    cout << "Array is empty: " << (arr.IsEmpty() ? "true" : "false") << endl;

    return 0;
}