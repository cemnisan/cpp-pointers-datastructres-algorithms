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
    // private
    StackNode *root;
    int length;

    void makeEmpty() {
        while(!isEmpty()) {
            pop();
        }
        root = NULL;
    }

public:
    Stack() : root(NULL), length(0) {}

    StackNode *begin() const { return root; }
    StackNode *end() const { return NULL; }

    bool isEmpty() const
    {
        // return root == NULL;
        return begin() == end();
    }

    int top()const {
        if (isEmpty()) {
            throw "Error: stack::pop() for stack is empty.";
        }

        // return root->data;
        return begin()->data;
    }

    void push(const int &value)
    {
        StackNode *tmp = new StackNode(value, root);
        root = tmp;
        length++;
    }

    void pop() {
        if (isEmpty()){
            throw "Error: stack::pop() for stack is empty.";
        }

        StackNode* tmp = root;
        root = tmp->next;
        delete tmp;
        length--;
    }

    int size() {
        return length;
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

    s.push(6);
    s.push(10);
    s.push(32);
    s.push(1);
    s.push(23932);
    s.pop();
    s.pop();
    s.push(12);

   try {
        cout << "Başlangıç değeri: " << s.top() << endl;
   } catch (const char* ex) {
       cout << ex << endl;
   }

    cout << "size: " << s.size() << endl;

    return 0;
}