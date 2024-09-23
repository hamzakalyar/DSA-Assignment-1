
class Stack {
private:
    int top;
    int maxStack;
    char* items;

public:
    Stack();             // Default constructor
    Stack(int max);      // Constructor with max size
    ~Stack();            // Destructor

    bool isEmpty();      // Check if stack is empty
    bool isFull();       // Check if stack is full
    void Push(char newItem); // Push item onto the stack
    void Pop(char& item);     // Pop item from the stack
};

#
