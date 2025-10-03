#include <iostream>

class test
{
private:
    int cars = 0;
    int people = 0;

    // constructor
public:
    test(int c, int p)
    {
        cars = c;
        people = p;
    }
};

main()
{
    std::cout << "Hello, Arena!" << std::endl;

    // array of integers
    int array[10]; // garbaged values undefined! initialize like this instead: array[10] = {} // all 0s
    array[0] = 5;

    // pointer to array
    int *arr = new int[10]; // new returns an integer pointer (to first element in memory block)
    arr[0] = 5;
    delete[] arr;  // free memory
    arr = nullptr; // avoid dangling pointer

    // dynamic array
    int size;
    std::cin >> size;
    int *dynArray = new int[size]; // dynamic array must be pointer

    // resizing dynamic array
    int newSize;
    std::cin >> newSize;
    int *newArray = new int[newSize];
    int elementsToCopy = (newSize < size) ? newSize : size; // copy min of old/new size
    for (int i = 0; i < elementsToCopy; i++)
    {
        newArray[i] = dynArray[i];
    }
    // order of this is important to avoid memory leak (we can't call delete on dynArray after we lose the pointer to it)
    delete[] dynArray;   // mark memory here as free
    dynArray = newArray; // point to new array

    int &ref = newArray[0];
    int copy = newArray[0];

    return 0;
}