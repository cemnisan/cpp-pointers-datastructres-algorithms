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
};

int main(){

    list l;
    
    cout << l.isEmpty() << endl;

    l.push_back(6);
    cout << l.isEmpty() << endl;


    return 0;
}