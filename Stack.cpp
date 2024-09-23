#include "Stack.h"
#include <iostream>

Stack::Stack() {
    maxStack = 100;
    top = -1;
    items = new char[maxStack];
}

Stack::Stack(int max) {
    maxStack = max;
    top = -1;
    items = new char[maxStack];
}

Stack::~Stack() {
    delete[] items;
}

bool Stack::isEmpty() {
    return (top == -1);
}

bool Stack::isFull() {
    return (top == maxStack - 1);
}

void Stack::Push(char newItem) {
    if (isFull()) {
        std::cout << "Stack is full. Cannot push new item." << std::endl;
        return;
    }
    items[++top] = newItem;
}

void Stack::Pop(char& item) {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop item." << std::endl;
        return;
    }
    item = items[top--];
}
