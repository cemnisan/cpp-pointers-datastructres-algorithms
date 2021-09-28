#include <iostream>
using namespace std;

// Constructor Node
class Node{
    public:
        Node(const int& data = 0,Node* next=NULL): data(data), next(next) { }
        int data;
        Node* next;
};

// Constructor List
class list{
    Node* tail;
    Node* root;
    public:
        list(){
            root = new Node();
            tail = root;
            tail->next = new Node();
        }

        Node* begin()const{ return root->next; }

        Node* end()const{ return tail->next; }

        // bool isEmpty()const{return root == NULL; } or
        bool isEmpty()const { 
            return begin() == end(); 
        }

        void push_back(const int& value){
           insert(end(),value);
        }

        void push_front(const int& value){
            insert(begin(),value);
        }

        void insert(Node* pos, const int& value){
            if(pos == end()){
                tail->next = new Node (value,end());
                tail = tail->next;

            } else {
                Node* tmp = root;
                
                while(tmp-> next != pos){
                    tmp = tmp->next;
                }
                tmp->next = new Node(value,tmp->next);
            }
        }

        int front()const{
            if(isEmpty())
                throw "Error: list::front() for list is empty";

            return begin()->data;
        }

        int back()const{
            if(isEmpty())
                throw "Error: list::back() for list is empty";
        
            Node* tmp = begin();

            while(tmp->next != end())
                tmp = tmp->next;
            
            return tmp->data;
        }

        void pop_back(){
            if(isEmpty())
            {
                throw "Error : list::pop_back() for list is empty.";
            }

            if (begin()->next == end())
            {
                delete root;
                root = NULL;
            }
            else
            {
                Node* tmp = begin();
                
                while(tmp->next->next != end())
                {
                    tmp = tmp->next;
                }
    
                delete tmp->next;
                tmp->next = NULL;
            }
        
        }

        void pop_front(){
            if (isEmpty())
            {
                throw "Error : list::pop_back() for list is empty.";
            }
            Node* tmp = root;
            root = tmp->next;
            delete tmp;
        }

        void print(){
            Node* tmp = begin();

            while (tmp != end()){
                cout << "data: " << tmp -> data << " ";
                cout << "next: " <<  tmp-> next << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

int main(){
    list l;
    cout << l.isEmpty() << endl;

    l.push_front(5);
    l.push_back(2);
    l.push_front(10);
    l.print();

    return 0;
}