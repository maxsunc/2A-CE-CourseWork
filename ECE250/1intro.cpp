#include <iostream>

class Vector2D
{
public:
    double x;
    double y;

    // Default constructor (required for arrays)
    Vector2D() : x(0.0), y(0.0) {}

    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}
};

// T(3n + 6) => O(n)

// merge sort
// if n=1, done O(1)
//  recursively sort A[1..ceil(n/2)] and A[ceil(n/2)]+1..n. O
//  3. merging the 2 sorted array O(n) just use two pointer

// T(n) = 2T(n/2) + O(n) => O(n log n)

int main()
{
    Vector2D obj1 = Vector2D(0.0, 0.0);        // Direct construction
    Vector2D obj2 = *(new Vector2D(0.0, 0.0)); // new + dereference (new keyword gives pointer to object always)
    // obj2[i] means obj2[0] points to first element, obj2[1] points to second element (4 bytes apart since double is 4 bytes)
    // strings
    std::string example; //

    // getting input like this compute 1 4
    std::cin >> example; // read until space
    std::cout << example << std::endl;
    // read next guy
    std::cin >> example; // reads until space again
    std::cout << example << std::endl;
    std::cin >> example; // reads until space again
    std::cout << example << std::endl;

    // 2d arrays
    int **arr = new int *[10]; // array of 10 int pointers
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = new int[10]; // each int pointer points to an array of 10 ints
    }

    // Don't forget to delete the allocated memory
    for (int i = 0; i < 10; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
