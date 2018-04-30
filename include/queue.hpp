#ifndef queue_HPP
#define queue_HPP
#include "LinkedList.hpp"
#include <iostream>

//Peter

//queue of integers using LinkedList

struct IntQueue
{
    //parameters here (using Linked List)
    IntegerNode *rear = nullptr;
    IntegerNode *front = nullptr;
    int size = 0;
    //methods
    void enqueue(int const data)
    {
        IntegerNode *newNode = new IntegerNode;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
        if (front == nullptr)
        {
            front = rear;
        }
    }

    int dequeue()
    {

        if (isEmpty() == false)
        {
            IntegerNode *current;
            current = front;
            int removedData = current->data;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }
    int getFront() const
    {
        if (!isEmpty)
            return front->data;
        else
        {
            std::cout << "queue is empty" << std::endl;
            exit(1);
        }
    }

    bool isEmpty() const
    {
        return size == 0;
    }
    int getSize() const
    {

        return size;
    }
    void clear()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

//Bonus : Queue of integers using Arrays

struct IntArrayQueue
{
    int front = 0;
    int rear = 0;
    int arrayQueue[100];
    int size = 0;
    //methods
    void enqueue(int const data)
    {
        if (isFull() == false)
        {
            size++;
            arrayQueue[rear] = data;
            rear++;
            if (rear == 100)
            {
                rear = 0;
            }
        }
        else
        {
            std::cout << "queue is full";
            exit(1);
        }
    }
    int dequeue()
    {
        if (isEmpty() == false)
        {
            size--;
            int removedData = arrayQueue[front];
            front++;
            if (front == 100)
            {
                front = 0;
            }
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }
    int getFront() const
    {
        if (!isEmpty)
            return arrayQueue[front];
        else
        {
            std::cout << "empty queue" << std::endl;
            exit(1);
        }
    }
    bool isFull() const
    {
        return size == 100;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    int getSize() const
    {
        return size;
    }
    void clear()
    {
        front = rear;
        size = 0;
    }
};

//queue of characters using LinkedList

struct CharQueue
{
    //parameters here (using Linked List)
    CharNode *rear = nullptr;
    CharNode *front = nullptr;
    int size = 0;
    //methods
    void enqueue(char const data)
    {
        CharNode *newNode = new CharNode;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
        if (front == nullptr)
        {
            front = rear;
        }
    }

    char dequeue()
    {
        if (isEmpty() == false)
        {
            CharNode *current = front;
            char removedData = front->data;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }
    char getFront() const
    {
        if (!isEmpty)
            return front->data;
        else
        {
            std::cout << "empty queue" << std::endl;
            exit(1);
        }
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    void clear()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

//Bonus : Queue of characters using Arrays
struct CharArrayQueue
{
    int front = 0;
    int rear = 0;
    int size = 0;
    char arrayQueue[100];
    //methods
    void enqueue(char const data)
    {
        if (isFull() == false)
        {
            size++;
            arrayQueue[rear] = data;
            rear++;
            if (rear == 100)
            {
                rear = 0;
            }
        }
        else
        {
            std::cout << "queue is full";
            exit(1);
        }
    }
    char dequeue()
    {
        if (isEmpty() == false)
        {
            size--;
            char removedData = arrayQueue[front];
            front++;
            if (front == 100)
            {
                front = 0;
            }
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }
    char getFront() const
    {
        if (!isEmpty)
            return arrayQueue[front];
        else
        {
            std::cout << " empty queue" << std::endl;
            exit(1);
        }
    }
    bool isFull() const
    {
        return size == 100;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    int getSize() const
    {
        return size;
    }
    void clear()
    {
        front = rear;
        size = 0;
    }
};

//queue of doubles using LinkedList

struct DoubleQueue
{
    //parameters here (using Linked List)
    DoubleNode *rear = nullptr;
    DoubleNode *front = nullptr;
    int size = 0;
    //methods
    void enqueue(double data)
    {
        DoubleNode *newNode = new DoubleNode;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
        if (front == nullptr)
        {
            front = rear;
        }
    }

    double dequeue()
    {

        if (isEmpty() == false)
        {
            DoubleNode *current;
            current = front;
            double removedData = current->data;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }

    double getFront() const
    {
        if (isEmpty)
            return front->data;
        else
        {
            std::cout << "queue is empty" << std::endl;
            exit(1);
        }
    }

    bool isEmpty() const
    {
        return size == 0;
    }
    int getSize() const
    {
        return size;
    }
    void clear()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

//Bonus : Queue of doubles using Arrays
struct DoubleArrayQueue
{
    int front = 0;
    int rear = 0;
    int size = 0;
    double arrayQueue[100];
    //methods
    void enqueue(double const data)
    {
        if (isFull() == false)
        {
            arrayQueue[rear] = data;
            rear++;
            size++;
            if (rear == 100)
            {
                rear = 0;
            }
        }
        else
        {
            std::cout << "queue is full";
            exit(1);
        }
    }
    double dequeue()
    {
        if (isEmpty() == false)
        {
            size--;
            char removedData = arrayQueue[front];
            front++;
            if (front == 100)
            {
                front = 0;
            }
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }
    double getFront() const
    {
        if (!isEmpty)
            return arrayQueue[front];
        else
        {
            std::cout << "empty queue" << std::endl;
            exit(1);
        }
    }
    bool isFull() const
    {
        return size == 100;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    int getSize() const
    {
        return size;
    }
    void clear()
    {
        front = rear;
        size = 0;
    }
};

#endif // queue_HPP
