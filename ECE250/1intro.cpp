#include <iostream>

int main()
{
    std::cout << " hello world" << std::endl;
    return 0;
}

// T(3n + 6) => O(n)

// merge sort
// if n=1, done O(1)
//  recursively sort A[1..ceil(n/2)] and A[ceil(n/2)]+1..n. O
//  3. merging the 2 sorted array O(n) just use two pointer
