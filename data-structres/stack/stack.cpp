#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
    StackNode(const int &data = 0, StackNode *next = NULL) : data(data), next(next) {}
};

class Stack
{
    StackNode *root;

public:
    Stack() : root(NULL) {}

    StackNode *begin() const { return root; }
    StackNode *end() const { return NULL; }

    bool isEmpty() const
    {
        // return root == NULL;
        return begin() == end();
    }

    void push(const int &value)
    {
        StackNode *tmp = new StackNode(value, root);
        root = tmp;
    }

    void pop() {
        if (isEmpty()){
            throw "Error: stack::pop() for stack is empty.";
        }

        StackNode* tmp = root;
        root = tmp->next;
        delete tmp;
    }

    void print()
    {
        StackNode* tmp = begin();
    
        while (tmp != end())
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main()
{
    Stack s;
    cout << s.isEmpty() << endl;
    s.push(6);
    s.push(1);
    s.push(3);
    s.push(5);
    cout << s.isEmpty() << endl;
    s.pop();
    s.print();

    return 0;
}