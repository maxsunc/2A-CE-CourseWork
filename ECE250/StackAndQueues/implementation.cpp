
#include <iostream>
#include <stdexcept>

// stack
class Stack
{
private:
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size = 10)
    {
        arr = new int[size];
        capacity = size;
        top = -1; // empty stack
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (top == capacity - 1)
        {
            // resize
            int newCapacity = capacity * 2;
            int *newArr = new int[newCapacity];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            throw std::out_of_range("Stack is empty");
        }
        top--;
    }

    int peek() const
    {
        if (top == -1)
        {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    int size() const
    {
        return top + 1;
    }
};

// queue
class Queue
{

private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 10)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int x)
    {
        if (count == capacity)
        {
            // resize
            int newCapacity = capacity * 2;
            int *newArr = new int[newCapacity];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[(front + i) % capacity];
            }
            delete[] arr;
            arr = newArr;
            front = 0;
            rear = capacity - 1;
            capacity = newCapacity;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        front = (front + 1) % capacity;
        count--;
    }

    int peek() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    int size() const
    {
        return count;
    }
};