#include <iostream>
using namespace std;

// Constructor Node
class Node
{
public:
    Node(const int &data = 0, Node *next = NULL) : data(data), next(next) {}
    int data;
    Node *next;
};

// Constructor List
class list
{
    Node *tail;
    Node *root;
    int length;

    Node *findPrev(Node *pos)
    {
        Node *tmp = root;
        Node *stop = end();

        while (tmp != stop && tmp->next != pos)
        {
            tmp = tmp->next;
        }
        return tmp;
    }

public:
    list()
    {
        length = 0;
        root = new Node();
        tail = root;
        tail->next = new Node();
    }

    // Destructor
    ~list()
    {
        clear();
        delete tail->next;
        delete tail;
    }

    list &operator=(const list &rhs)
    {
        return assign(rhs);
    }

    // Overload
    list &assign(const list &rhs)
    {
        clear();
        Node *tmp = rhs.begin();
        while (tmp != rhs.end())
        {
            push_back(tmp->data);
            tmp = tmp->next;
        }
        return *this;
    }

    Node *begin() const { return root->next; }
    Node *end() const { return tail->next; }

    // bool isEmpty()const{return root == NULL; } or
    bool isEmpty() const
    {
        return begin() == end();
    }

    void push_back(const int &value)
    {
        insert(end(), value);
    }

    void push_front(const int &value)
    {
        insert(begin(), value);
    }

    int size() const
    {
        return length;
    }

    void insert(Node *pos, const int &value)
    {
        if (pos == end())
        {
            tail->next = new Node(value, end());
            tail = tail->next;
        }
        else
        {
            Node *tmp = findPrev(pos);
            if (tmp == end())
                throw "Error: list::insert() for pos in not list.";

            tmp->next = new Node(value, tmp->next);
        }
        length++;
    }

    // Overload
    void insert(Node *pos, int n, const int &value)
    {
        for (int i = 0; i < n; i++)
        {
            insert(pos, value);
        }
    }

    //Overload
    void insert(Node *pos, Node *first, Node *last)
    {
        while (first != last)
        {
            insert(pos, first->data);
            first = first->next;
        }
    }

    int front() const
    {
        if (isEmpty())
            throw "Error: list::front() for list is empty";

        return begin()->data;
    }

    int back() const
    {
        if (isEmpty())
            throw "Error: list::back() for list is empty";

        return tail->data;
    }

    void erase(Node *pos)
    {
        if (isEmpty())
        {
            throw "Error: list::erase() for list is empty.";
        }

        Node *tmp = root;
        if (pos == end() || pos == tail)
        {

            pos = tail;
            tmp = findPrev(pos);

            tmp->next = pos->next;
            tail = tmp;
        }
        else
        {
            tmp = findPrev(pos);

            if (pos == end())
            {
                throw "Error: list::erase() for pos is not list.";
            }
            tmp->next = pos->next;
        }
        delete pos;
        length--;
    }

    // Overload
    void erase(Node *first, Node *last)
    {
        Node *tmp;
        while (first != last)
        {
            tmp = first;
            first = first->next;
            erase(tmp);
        }
    }

    void clear()
    {
        erase(begin(), end());
    }

    void pop_back()
    {
        erase(end());
    }

    void pop_front()
    {
        erase(begin());
    }

    Node *find(const int &value) const
    {
        Node *tmp = begin();
        Node *stop = end();
        while (tmp != stop && tmp->data != value)
        {
            tmp = tmp->next;
        }
        return tmp;
    }

    void print()
    {
        Node *tmp = begin();

        while (tmp != end())
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}