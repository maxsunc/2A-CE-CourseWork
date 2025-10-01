#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int maxSize = 50;
    // better to use a hashmap for distinct values for O(1) lookup
    float *seenElements = new float[maxSize]{}; // must initialize like this for all 0s
    // assume the float values are all > 0
    float top3[3] = {};
    // initialize to -1
    // 2 = least of the top 3
    // 0 = highest of the top 3
    for (int i = 0; i < 3; i++)
    {
        top3[i] = -1;
    }

    int currentSize = 0;

    // 56.64
    // 45.65
    // -1
    float input = 0;
    do
    {
        cin >> input;
        if (input != -1)
        {
            // some sort of float value inside of input
            // see if we need to resize
            if (currentSize >= maxSize)
            {
                // create a new seenElements with 2x size
                maxSize *= 2;
                float *dynElements = new float[maxSize]{};
                // copy over all elements up to currentSize - 1
                for (int i = 0; i < currentSize; i++)
                {
                    dynElements[i] = seenElements[i];
                }
                // switch pointers, delete old pointer
                delete[] seenElements;
                seenElements = dynElements;
            }

            // check if its not inside of seen elements
            bool alreadySeen = false;
            for (int i = 0; i < currentSize; i++)
            {
                if (seenElements[i] == input)
                {
                    alreadySeen = true;
                    break;
                }
            }
            if (!alreadySeen)
            {

                // add to place of current size
                seenElements[currentSize] = input;
                // increment currentSize
                currentSize++;
                // iterate thru top3 if its bigger than any shift everything down one (starting from i) then replace at i
                for (int i = 0; i < 3; i++)
                {
                    if (input > top3[i])
                    {
                        // shift elements to the right
                        for (int j = 2; j > i; j--)
                        {
                            top3[j] = top3[j - 1];
                        }
                        top3[i] = input;
                        break; // Important: stop after inserting
                    }
                }
            }
        }

    } while (input != -1);
    // print all the stuff
    for (int i = 0; i < 3; i++)
    {
        if (top3[i] == -1)
        {
            cout << "NA";
        }
        else
        {
            cout << fixed << setprecision(2) << top3[i];
        }
        if (i < 2)
            cout << " ";
    }
    cout << endl;
    cout << currentSize << endl;
    // average everything
    float sum = 0;
    for (int i = 0; i < currentSize; i++)
    {
        sum += seenElements[i];
    }
    cout << fixed << setprecision(2) << sum / currentSize << endl;
}