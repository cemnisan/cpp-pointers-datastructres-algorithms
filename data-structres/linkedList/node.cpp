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
    Node* root;
    public:
        list(): root(NULL){}

        Node* begin()const{ return root; }

        Node* end()const{ return NULL; }

        // bool isEmpty()const{return root == NULL; } or
        bool isEmpty()const { 
            return begin() == end(); 
        }

        void push_back(const int& value){
            if(isEmpty()){
                root = new Node(value);
            }
            else{
                Node* tmp = begin();

                while(tmp->next != end()){
                    tmp = tmp->next;
                }
                tmp->next = new Node(value);
            }
        }

        void push_front(const int& value){
            Node* tmp = new Node(value);
            tmp-> next = root;
            root = tmp;
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

        void print(){
            Node* tmp = begin();

            while (tmp != end()){
                cout << tmp -> data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

int main(){
    list l;

    l.push_back(5);
    l.push_back(10);

    l.push_front(3);
    
    cout << "Front: " <<l.front() << endl;
    cout << "Back: " << l.back() << endl;

    return 0;
}